#include "stmt.h"
UnaryStmtGen *getUnaryOpertorStatement(const UnaryOperator *pOperator,  int shift);
BinaryStmtGen *getBinaryStatement(const BinaryOperator *pOperator, int shift);

UnaryStmtGen *getCastGen(const ImplicitCastExpr *pExpr,  int shift);
UnaryStmtGen *getEmptyUnaryGen(const Expr *pExpr,  int shift);

UnaryStmtGen *getDeclName(const DeclRefExpr *pExpr);

StmtGen *getStmtGen(ConstStmtIterator i, int shift);

CompoundStmtGen *getCompoundStmtOutputGenerator(Expr *pExpr, int shift);

//-------------------------------------------------------------------------------------------------
// Определение и тестовый вывод основных параметров составного оператора
void getCompoundStmtParameters(const CompoundStmt* CS,int shift) {
    std::string strShift = "";
    for(int i = 0; i < shift; i++) {strShift += "  ";}
    bool isBodyEmpty = CS->body_empty();
    if(isBodyEmpty) {
        llvm::outs() << "  Body is Empty\n";
    } else {
        llvm::outs() << "  Body isn't Empty\n";
    }
    unsigned bodySize = CS->size();
    llvm::outs() << "  Body size = " << bodySize << " \n";

    //getCompoundStmtGenerator(CS, 0);

    for(CompoundStmt::const_body_iterator i = CS->body_begin(); i != CS->body_end(); i++) {
        char* stmtName = (char*)((*i)->getStmtClassName());
        Stmt::StmtClass stmtClass = (*i)->getStmtClass();
        llvm::outs() << "      It is " << stmtName << " stmtClass = " <<  stmtClass << "\n";
        const clang::BinaryOperator* op = (BinaryOperator*)(*i);
        llvm::outs() << "      operator: " << op->getOpcodeStr() <<"\n";
        for(BinaryOperator::const_child_iterator i = op->child_begin(); i != op->child_end(); i++)
        {
            llvm::outs()  << "          stmt class   " <<(*i)->getStmtClassName() << "\n";
            if (std::string((*i)->getStmtClassName()).compare("ImplicitCastExpr")==0)
            {
                const ImplicitCastExpr* exp = (ImplicitCastExpr*)(*i);
                llvm::outs()  << "             stmt class   " <<exp->child_begin()->getStmtClassName() << "\n";
                const DeclRefExpr* var = (DeclRefExpr*)(*(exp->child_begin()));
                llvm::outs()  << "                var ref ID   " <<var->getFoundDecl()<< "\n";

            }
        }
        //auto isAssigmentOperator = ;
    }
}

CompoundStmtGen* getCompoundStmtGenerator(const CompoundStmt *CS, int shift, bool isDecorator) {
    CompoundStmtGen* compoundStmt = new CompoundStmtGen;
    compoundStmt->value = "seq";
    if (isDecorator)
        compoundStmt->value += " > @";
    compoundStmt->shift = shift;
    for(CompoundStmt::const_body_iterator i = CS->body_begin(); i != CS->body_end(); i++) {
        // Костыльное решение для тестового выводо
        char* stmtName = (char*)((*i)->getStmtClassName());
        if (strcmp(stmtName , "ImplicitCastExpr") == 0)
        {
            CompoundStmtGen *stmtGen = getCompoundStmtOutputGenerator((ImplicitCastExpr*)(*i),shift + 1);
            compoundStmt->Add(stmtGen);
            continue;
        }
        StmtGen *stmtGen = getStmtGen(i, shift + 1);
        if (stmtGen != nullptr)
            compoundStmt->Add(stmtGen);
    }
    return compoundStmt;
}
//Временное решение для вывода
CompoundStmtGen *getCompoundStmtOutputGenerator(Expr *pExpr, int shift) {
    CompoundStmtGen* compoundStmt = new CompoundStmtGen;
    compoundStmt->value = "seq";
    compoundStmt->shift = shift;
    // Вывод переменной
    UnaryStmtGen* unaryStmtGen = new UnaryStmtGen;
    unaryStmtGen-> shift = shift + 1;
    unaryStmtGen->value = "stdout ";
    unaryStmtGen->postfix = ".as-string";
    DeclRefExpr *declExpr = (DeclRefExpr *)(*(pExpr->child_begin()));
    unaryStmtGen->nestedStmt = getDeclName(declExpr);
    compoundStmt->Add(unaryStmtGen);
    // Вывод перевода строки
    unaryStmtGen = new UnaryStmtGen;
    unaryStmtGen-> shift = shift + 1;
    unaryStmtGen-> value = R"(stdout "\n")";
    unaryStmtGen-> nestedStmt = nullptr;
    compoundStmt->Add(unaryStmtGen);
    return compoundStmt;
}

StmtGen *getStmtGen(ConstStmtIterator i, int shift) {
    StmtGen* stmtGen = nullptr;
    char* stmtName = (char*)((*i)->getStmtClassName());
    if (strcmp(stmtName ,"BinaryOperator") == 0)
    {
        const BinaryOperator* op = (BinaryOperator*)(*i);
        BinaryStmtGen* binaryStmtGen = getBinaryStatement(op, shift);
        binaryStmtGen->shift  = shift;
        stmtGen = binaryStmtGen;
    }
    else if (strcmp(stmtName , "ParenExpr") == 0)
    {
        const ParenExpr* op = (ParenExpr*)(*i);
        UnaryStmtGen* unaryStmtGen = getEmptyUnaryGen(op, shift);
        unaryStmtGen->shift  = shift;
        stmtGen = unaryStmtGen;
    }
    else if (strcmp(stmtName , "ImplicitCastExpr") == 0)
    {
        const ImplicitCastExpr* op = (ImplicitCastExpr*)(*i);
        UnaryStmtGen* unaryStmtGen = getCastGen(op, shift);
        unaryStmtGen->shift  = shift;
        stmtGen = unaryStmtGen;
    }
    else if(strcmp(stmtName , "DeclRefExpr") == 0)
    {
        const DeclRefExpr* op = (DeclRefExpr*)(*i);
        UnaryStmtGen* unaryStmtGen = getDeclName(op);
        unaryStmtGen->shift  = shift;
        stmtGen = unaryStmtGen;
    }
    else if (strcmp(stmtName ,"UnaryOperator") == 0)
    {
        const UnaryOperator* op = (UnaryOperator*)(*i);
        UnaryStmtGen* unaryStmtGen = getUnaryOpertorStatement(op, shift);
        unaryStmtGen->shift  = shift;
        stmtGen = unaryStmtGen;
    }
    else if(strcmp(stmtName , "CompoundStmt") == 0)
    {
        const CompoundStmt* cs = (CompoundStmt*)(*i);
        CompoundStmtGen* compoundStmtGen = getCompoundStmtGenerator(cs,shift);
        stmtGen = compoundStmtGen;
    }
    return stmtGen;
}

// Метод для получения имени переменной.
UnaryStmtGen *getDeclName(const DeclRefExpr *pExpr) {
    UnaryStmtGen* unaryStmtGen = new UnaryStmtGen;
    //pExpr->printPretty();
    unaryStmtGen->value = AbstractGen::identifiers[reinterpret_cast<uint64_t>(pExpr->getFoundDecl())];
    unaryStmtGen-> nestedStmt = nullptr;
    return  unaryStmtGen;
}

UnaryStmtGen *getCastGen(const ImplicitCastExpr *pExpr, int shift) {
    return getEmptyUnaryGen(pExpr,shift + 1);
}

UnaryStmtGen *getEmptyUnaryGen(const Expr *pExpr, int shift) {
    UnaryStmtGen* unaryStmtGen = new UnaryStmtGen;
    unaryStmtGen->value = "";
    unaryStmtGen-> nestedStmt =  getStmtGen(pExpr->child_begin(), shift + 1);
    return  unaryStmtGen;

}
UnaryStmtGen *getUnaryOpertorStatement(const UnaryOperator *pOperator,  int shift) {
    UnaryStmtGen* unaryStmtGen = new UnaryStmtGen;
    std::string opName = pOperator->getOpcodeStr(pOperator->getOpcode()).str();
    if (opName.compare("-") == 0)
    {
        unaryStmtGen->postfix = ".neg";
    }
    unaryStmtGen-> nestedStmt =  getStmtGen(pOperator->child_begin(), shift + 1);
    return  unaryStmtGen;
}
BinaryStmtGen *getBinaryStatement(const BinaryOperator *pOperator, int shift) {
    BinaryStmtGen* binaryStmtGen = new BinaryStmtGen;
    std::string opName = pOperator->getOpcodeStr().str();
    if (opName.compare("=") == 0)
    {
        binaryStmtGen->value = ".write ";
    }
    else if (opName.compare("+") == 0)
    {
        binaryStmtGen->value = ".add ";
    }
    else if (opName.compare("-") == 0)
    {
        binaryStmtGen->value = ".sub ";
    }
    else if (opName.compare("*") == 0)
    {
        binaryStmtGen->value = ".mul ";
    }
    else if (opName.compare("/") == 0)
    {
        binaryStmtGen->value = ".div ";
    }
    else if (opName.compare("%") == 0)
    {
        binaryStmtGen->value = ".mod ";
    }
    else if (opName.compare("==") == 0)
    {
        binaryStmtGen->value = ".eq ";
    }
    else if (opName.compare("!=") == 0)
    {
        binaryStmtGen->value = ".neq ";
    }
    else if (opName.compare("<") == 0)
    {
        binaryStmtGen->value = ".less ";
    }
    else if (opName.compare("<=") == 0)
    {
        binaryStmtGen->value = ".leq ";
    }
    else if (opName.compare(">") == 0)
    {
        binaryStmtGen->value = ".greater ";
    }
    else if (opName.compare(">=") == 0)
    {
        binaryStmtGen->value = ".geq ";
    }
    else
    {
        binaryStmtGen->value = "";
    }
    binaryStmtGen -> left = getStmtGen(pOperator->child_begin(), shift + 1);
    binaryStmtGen -> right = getStmtGen(++pOperator->child_begin(), shift + 1);


    return binaryStmtGen;

}

