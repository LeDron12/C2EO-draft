#include "stmt.h"

BinaryStmtGen *getBinaryStatement(const BinaryOperator *pOperator, int shift);

UnaryStmtGen *getCastGen(const ImplicitCastExpr *pExpr, int i);

UnaryStmtGen *getDeclName(const DeclRefExpr *pExpr);

StmtGen *getStmtGen(ConstStmtIterator i, int shift);

//-------------------------------------------------------------------------------------------------
// Определение и тестовый вывод основных параметров составного оператора
void getCompoundStmtParameters(const CompoundStmt* CS, int shift) {
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

    getCompoundStmtGenerator(CS, 0);

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
                llvm::outs()  << "                var ref ID   " <<var->getDecl()->getID() << "\n";

            }
        }
        //auto isAssigmentOperator = ;
    }
}

CompoundStmtGen* getCompoundStmtGenerator(const CompoundStmt *CS,  int shift, bool isDecorator) {
    CompoundStmtGen* compoundStmt = new CompoundStmtGen;
    compoundStmt->value = "seq";
    if (isDecorator)
        compoundStmt->value += " > @";
    compoundStmt->shift = shift;
    for(CompoundStmt::const_body_iterator i = CS->body_begin(); i != CS->body_end(); i++) {
        StmtGen *stmtGen = getStmtGen(i, shift + 1);
        if (stmtGen != nullptr)
            compoundStmt->Add(stmtGen);
    }
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
    return stmtGen;
}

// Метод для получения имени переменной.
UnaryStmtGen *getDeclName(const DeclRefExpr *pExpr) {
    UnaryStmtGen* unaryStmtGen = new UnaryStmtGen;
    unaryStmtGen->value = AbstractGen::identifiers[pExpr->getDecl()->getID()];
    unaryStmtGen-> nestedStmt = nullptr;
    return  unaryStmtGen;
}

UnaryStmtGen *getCastGen(const ImplicitCastExpr *pExpr, int shift) {
    UnaryStmtGen* unaryStmtGen = new UnaryStmtGen;
    unaryStmtGen->value = "";
    unaryStmtGen-> nestedStmt =  getStmtGen(pExpr->child_begin(), shift + 1);
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
    else
    {
        binaryStmtGen->value = "";
    }
    binaryStmtGen -> left = getStmtGen(pOperator->child_begin(), shift + 1);
    binaryStmtGen -> right = getStmtGen(++pOperator->child_begin(), shift + 1);


    return binaryStmtGen;

}

