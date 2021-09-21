// Функции, используемые при анализе переменных

#include "vardecl.h"
//#include "generator.h"

// Определение и тестовый вывод основных параметров описания переменных
void getVarDeclParameters(const VarDecl *VD) {
    // Имя переменной
    auto varName = VD->getNameAsString();
    llvm::outs() << "Name of Variable: " << varName << "\n";
    llvm::outs() << "  Var Kind Name: " << VD->getDeclKindName() << "\n";

    TypeInfo typeInfo = VD->getASTContext().getTypeInfo(VD->getType());
    auto typeSize = typeInfo.Width;
    auto fieldAlign = typeInfo.Align;
    llvm::outs() << "  Size = " << typeInfo.Width << ", Align = " << typeInfo.Align << "\n";

    // Получение типа переменной
    ///std::string typeName{"any value"};
    ///StringRef varTypeName(typeName);
    ////auto qualType = VD->getType();
    QualType qualType = VD->getType();
    const IdentifierInfo* typeId = qualType.getBaseTypeIdentifier();
    ////varTypeName = typeId->getName();
    ////llvm::outs() << "  Type is " << varTypeName << "\n";
    if(typeId != nullptr) {
        llvm::outs() << "  Type is " << typeId->getName() << "\n";
    } else {
        llvm::outs() << "  The problem to identify type name\n";
    }

    auto typePtr = qualType.getTypePtr();
    if(typePtr->isBuiltinType()) {
        llvm::outs() << "  It is Builtin type\n";
//         BuiltinType* btPtr = dynamic_cast<BuiltinType*>(typePtr);
//         if(btPtr != nullptr) {
//             llvm::outs() << "  It is Possible to convert into Builtin type\n";
//         } else {
//             llvm::outs() << "  It is Impossible to convert into Builtin type\n";
//         }
    } else {
        llvm::outs() << "  It is not Builtin type\n";
    }
    //auto kind = typePtr->getKind();

    if(typePtr->isCharType()) {
        if(typePtr->isSignedIntegerType())
            llvm::outs() << "    -->signedCharType\n";
        else
            llvm::outs() << "    -->unsignedCharType\n";
    } else if(typePtr->isBooleanType()) {
        llvm::outs() << "    -->isBooleanType\n";
    } else if(typePtr->isRealFloatingType()) {
        llvm::outs() << "    -->isRealFloatingType\n";
    } else if(typePtr->isIntegerType()) {
        if(typePtr->isSignedIntegerType())
            llvm::outs() << "    -->signedIntegerType\n";
        else
            llvm::outs() << "    -->unsignedIntegerType\n";
    }

    llvm::outs() << "  !!! class name = " << typePtr->getTypeClassName() << "\n";

    // StorageClass getStorageClass() const
    // Показывает на явное описани того или иного класса памяти в тексте программы
    // Наверное не во всех случаях полезно
    auto storageClass = VD->getStorageClass();
    llvm::outs() << "  storage class is ";
    switch(storageClass) {
        case SC_None:           llvm::outs() << "None";          break;
        case SC_Extern:         llvm::outs() << "Extern";        break;
        case SC_Static:         llvm::outs() << "Static";        break;
        case SC_PrivateExtern:  llvm::outs() << "PrivateExtern"; break;
        case SC_Auto:           llvm::outs() << "Auto";          break;
        case SC_Register:       llvm::outs() << "Register";      break;
        default:                llvm::outs() << "NOT DEFINED";
    }
    llvm::outs() << "\n";

    // Проверка на размещение переменной в локальной памяти
    auto inLocalStorage = VD->hasLocalStorage();
    if(inLocalStorage) {
        llvm::outs() << "  Local Storage\n";
    } else {
        llvm::outs() << "  not Local Storage\n";
    }
    // Проверка на статическую локальную переменную
    auto staticLocal = VD->isStaticLocal();
    if(staticLocal) {
        llvm::outs() << "  Static Local\n";
    } else {
        llvm::outs() << "  not Static Local\n";
    }
    // Внешняя переменная (описатель external)
    auto extStorage = VD->hasExternalStorage();
    if(extStorage) {
        llvm::outs() << "  External Storage Defenition\n";
    } else {
        llvm::outs() << "  not External Storage Definition\n";
    }
    // Размещение переменной в глобальной памяти
    // Касается глобальных и статических переменных
    auto globalStorage = VD->hasGlobalStorage();
    if(globalStorage) {
        llvm::outs() << "  has GlobalStorage\n";
    } else {
        llvm::outs() << "  has not GlobalStorage\n";
    }
    // Переменная с локальной видимостью
    auto localVarDecl = VD->isLocalVarDecl();
    if(localVarDecl) {
        llvm::outs() << "  is Local VarDecl\n";
    } else {
        llvm::outs() << "  is not Local VarDecl\n";
    }
    // Переменная или параметр с локальной видимостью
    auto localVarDeclOrParm = VD->isLocalVarDeclOrParm();
    if(localVarDeclOrParm) {
        llvm::outs() << "  is Local VarDecl or Parm\n";
    } else {
        llvm::outs() << "  is not Local VarDecl or Parm\n";
    }
    // Наличие начальной инициализации
    auto isInit = VD->hasInit();
    std::string str = "";
    if(isInit) {
        llvm::outs() << "  has Initializer\n";
        initValueAnalysis(VD, str);
    } else {
        llvm::outs() << "  has not Initializer\n";
    }
/*
    // Проверка, что целочисленная переменная является глобальной
    if (globalStorage && !extStorage && !staticLocal)
    {
        //!! можно заменить на автоматическую память или вообще убрать, породив только строку
        IntVariable* var = new IntVariable; !!

        var->name = "c_" + varName;
        var->type = "varint";
        var->value  = value;
        CodeGenerator::vars.push_back(var);
    }
*/
  //VD->dump();
}

// Анализ полученного начального значения с тестовым выводом его
// и формированием строки со значением на выходе
void initValueAnalysis(const VarDecl *VD, std::string &str) {
    APValue *initVal = VD->evaluateValue();
    if(initVal != nullptr) {
        llvm::outs() << "    Initial Value = ";
        if(initVal->isInt()) {
            auto intValue = initVal->getInt().getExtValue();
            llvm::outs() << intValue;
            str = std::to_string(intValue);
        } else if(initVal->isFloat()) {
            //auto floatValue = initVal->getFloat().convertToFloat();
            auto floatValue = initVal->getFloat().convertToDouble();
            llvm::outs() << floatValue;
            str = std::to_string(floatValue);
        }
        llvm::outs() << "\n";
    } else {
        llvm::outs() << "    no Initial Value\n";
    }
}

