#include <iostream>
#include <cstdio>
#include <clang-c/Index.h>  // This is libclang.
using namespace std;

ostream& operator<<(ostream& stream, const CXString& str)
{
    stream << clang_getCString(str);
    clang_disposeString(str);
    return stream;
}

//------------------------------------------------------------------------------
// static void PrintCursor(CXCursor Cursor) {
//   if (clang_isInvalid(Cursor.kind)) {
//     CXString ks = clang_getCursorKindSpelling(Cursor.kind);
//     printf("Invalid Cursor => %s", clang_getCString(ks));
//     clang_disposeString(ks);
//   }
//   else {
//     CXString string, ks;
//     CXCursor Referenced;
//     unsigned line, column;
// 
//     ks = clang_getCursorKindSpelling(Cursor.kind);
//     string = clang_getCursorSpelling(Cursor);
//     printf("%s=%s", clang_getCString(ks),
//                     clang_getCString(string));
//     clang_disposeString(ks);
//     clang_disposeString(string);
// 
//     Referenced = clang_getCursorReferenced(Cursor);
//     if (!clang_equalCursors(Referenced, clang_getNullCursor())) {
//       CXSourceLocation Loc = clang_getCursorLocation(Referenced);
//       clang_getInstantiationLocation(Loc, 0, &line, &column, 0);
//       printf(":[%d:%d]", line, column);
//     }
// 
//     if (clang_isCursorDefinition(Cursor))
//       printf(" (Definition)");
//   }
// }

//------------------------------------------------------------------------------
static void PrintCursor(CXCursor Cursor) {
  if (clang_isInvalid(Cursor.kind)) {
    CXString ks = clang_getCursorKindSpelling(Cursor.kind);
    printf("Invalid Cursor => %s", clang_getCString(ks));
    clang_disposeString(ks);
  }
  else {
    CXString string, ks;
    CXCursor Referenced;
    unsigned line, column;
    CXCursor SpecializationOf;
    
    ks = clang_getCursorKindSpelling(Cursor.kind);
    string = clang_getCursorSpelling(Cursor);
    printf("%s=%s", clang_getCString(ks),
                    clang_getCString(string));
    clang_disposeString(ks);
    clang_disposeString(string);

    Referenced = clang_getCursorReferenced(Cursor);
    if (!clang_equalCursors(Referenced, clang_getNullCursor())) {
      CXSourceLocation Loc = clang_getCursorLocation(Referenced);
      clang_getInstantiationLocation(Loc, 0, &line, &column, 0);
      printf(":%d:%d", line, column);
    }

    if (clang_isCursorDefinition(Cursor))
      printf(" (Definition)");
    
    switch (clang_getCursorAvailability(Cursor)) {
      case CXAvailability_Available:
        break;
        
      case CXAvailability_Deprecated:
        printf(" (deprecated)");
        break;
        
      case CXAvailability_NotAvailable:
        printf(" (unavailable)");
        break;
    }
    
    if (Cursor.kind == CXCursor_IBOutletCollectionAttr) {
      CXType T =
        clang_getCanonicalType(clang_getIBOutletCollectionType(Cursor));
      CXString S = clang_getTypeKindSpelling(T.kind);
      printf(" [IBOutletCollection=%s]", clang_getCString(S));
      clang_disposeString(S);
    }
    
    if (Cursor.kind == CXCursor_CXXBaseSpecifier) {
      enum CX_CXXAccessSpecifier access = clang_getCXXAccessSpecifier(Cursor);
      unsigned isVirtual = clang_isVirtualBase(Cursor);
      const char *accessStr = 0;

      switch (access) {
        case CX_CXXInvalidAccessSpecifier:
          accessStr = "invalid"; break;
        case CX_CXXPublic:
          accessStr = "public"; break;
        case CX_CXXProtected:
          accessStr = "protected"; break;
        case CX_CXXPrivate:
          accessStr = "private"; break;
      }      
      
      printf(" [access=%s isVirtual=%s]", accessStr,
             isVirtual ? "true" : "false");
    }
    
    SpecializationOf = clang_getSpecializedCursorTemplate(Cursor);
    if (!clang_equalCursors(SpecializationOf, clang_getNullCursor())) {
      CXSourceLocation Loc = clang_getCursorLocation(SpecializationOf);
      CXString Name = clang_getCursorSpelling(SpecializationOf);
      clang_getInstantiationLocation(Loc, 0, &line, &column, 0);
      printf(" [Specialization of %s:%d:%d]", 
             clang_getCString(Name), line, column);
      clang_disposeString(Name);
    }
  }
}

//------------------------------------------------------------------------------
// Табулятор для отступа в дочерних выводах данных
std::string tabSize = "  ";
std::string tab = "";
int level = 0;

// Тестовая функция, осуществляющая вывод разновидности результата
void testOutKindResult(CXEvalResultKind r) {
//         CXEval_Int: // = 1
//         CXEval_Float = 2,
//         CXEval_ObjCStrLiteral = 3,
//         CXEval_StrLiteral = 4,
//         CXEval_CFStr = 5,
//         CXEval_Other = 6,
    switch(r) {
        case CXEval_Int:
            std::cout << "CXEvalResultKind = CXEval_Int\n";
            break;
        case CXEval_Float:
            std::cout << "CXEvalResultKind = CXEval_Float\n";
            break;
        case CXEval_ObjCStrLiteral:
            std::cout << "CXEvalResultKind = CXEval_ObjCStrLiteral\n";
            break;
        case CXEval_StrLiteral:
            std::cout << "CXEvalResultKind = CXEval_StrLiteral\n";
            break;
        case CXEval_CFStr:
            std::cout << "CXEvalResultKind = CXEval_CFStr\n";
            break;
        case CXEval_Other:
            std::cout << "CXEvalResultKind = CXEval_Other\n";
            break;
        default:
            std::cout << "CXEvalResultKind is Unkown \n";
    }
}

// Функция, осуществляющая более детальный анализ артефакта по его виду
void extendedAnalysis(CXCursor c, std::string &t)
{
    //??? CINDEX_LINKAGE CXString clang_getCursorUSR(CXCursor);
    auto usrStr = clang_getCursorUSR(c);
    
    // Перетащил из функции обхода анализа артефакта, указанного курсором
    auto kind = clang_getCursorKind(c);
    auto spelling = clang_getCursorSpelling(c);
    auto kindSpelling = clang_getCursorKindSpelling(kind);
    auto cursorName = clang_getCursorDisplayName(c);

    CXSourceRange range = clang_getCursorExtent(c);
    CXSourceLocation location = clang_getRangeStart(range);
    CXFile file;
    unsigned line;
    unsigned column;
    //clang_getFileLocation(location, &file, &line, &column, NULL);
    clang_getFileLocation(location, nullptr, &line, &column, nullptr);
    
    //cout << tab << "Cursor '" << spelling << "' of kind\t '"
//     cout << tab << level << ": Cursor '" << spelling << "' of kind\t '"
//         << kindSpelling << "'" 
//         << " (" << kind << ")\tlocation[" << line << ":" << column << "] --> "
//         << cursorName << " ??? " << usrStr << "\n";

    PrintCursor(c);
    std::cout << "\n";

    // Проверка на некорректный курсор
    //if(clang_isInvalid(kind) {
    //    cout << "Invalid cursor!!!\n";
    //    exit(-1);
    //}
    // Проверка на некорректное объявление с завершением анализа
//     if(clang_isInvalidDeclaration(c)) {
//         cout << "Invalid declaration!!!\n";
//         exit(-1);
//     }
    
    const char* str = nullptr;
    // CINDEX_LINKAGE CXEvalResult clang_Cursor_Evaluate(CXCursor C);
    auto ce = clang_Cursor_Evaluate(c);
    // CINDEX_LINKAGE CXEvalResultKind clang_EvalResult_getKind(CXEvalResult E);
    auto cek =  clang_EvalResult_getKind(ce);
    // Проверка разновидности результата
/*    
    testOutKindResult(cek);
    // Проверка дополнительных параметров для каждого вида артефактов
    switch(kind) {
        case CXCursor_VarDecl:
            // Проверка типа переменной
            // CINDEX_LINKAGE CXType clang_getCursorType(CXCursor C);
            // CINDEX_LINKAGE CXString clang_getTypeSpelling(CXType CT);
            cout << t << " \\_ type is: " << clang_getTypeSpelling(clang_getCursorType(c)) << "\n";
            break;
        case CXCursor_IntegerLiteral:
            // Проверка целочисленной константы (литерала)
            // CINDEX_LINKAGE CXEvalResult clang_Cursor_Evaluate(CXCursor C);
            // CINDEX_LINKAGE int clang_EvalResult_getAsInt(CXEvalResult E);
            cout << t << " \\_ int value = " << clang_EvalResult_getAsInt(ce) << "\n";
            break;
        case CXCursor_FloatingLiteral:
            // Проверка целочисленной константы (литерала)
            // CINDEX_LINKAGE CXEvalResult clang_Cursor_Evaluate(CXCursor C);
            // CINDEX_LINKAGE double clang_EvalResult_getAsDouble(CXEvalResult E);
            cout << t << " \\_ int value = " << clang_EvalResult_getAsDouble(ce) << "\n";
            break;
        case CXCursor_BinaryOperator:
            // Проверка типа переменной
            // CINDEX_LINKAGE CXType clang_getCursorType(CXCursor C);
            // CINDEX_LINKAGE CXString clang_getTypeSpelling(CXType CT);
            cout << t << " \\_ binary operator type is: " << clang_getTypeSpelling(clang_getCursorType(c)) << "\n";
            
            // Попытка вывести строку с результатом (ожидаю операцию)
            cout << "before\n";
            str = clang_EvalResult_getAsStr(ce);
            cout << "after\n";
//             if(str != nullptr) {
//                 cout << t << "    " << str << "\n";
//                 printf("%s\n", str);
//             } else {
//                 cout << "Incorrect str = nullptr\n"; 
//             }
            clang_EvalResult_dispose(ce);
            cout << "\n";
            break;
        case CXCursor_UnexposedExpr:
            // Проверка типа переменной
            // CINDEX_LINKAGE CXType clang_getCursorType(CXCursor C);
            // CINDEX_LINKAGE CXString clang_getTypeSpelling(CXType CT);
            cout << t << " \\_ binary operator is: " << clang_getTypeSpelling(clang_getCursorType(c)) << "\n";
            break;
        default:
            cout << t << " \\_ Unknown kind\n";
    }
*/
}



// Используется визитер следующего типа
//typedef enum CXChildVisitResult (*CXCursorVisitor)(CXCursor cursor, CXCursor parent, CXClientData client_data);

enum CXChildVisitResult visit (CXCursor c, CXCursor parent, CXClientData client_data)
{
    // Функция, осуществляющая более детальный анализ артефакта
    extendedAnalysis(c, tab);
    
    // Попытка использовать рекурсию вместо рекурсивного обхода.
    std::string oldTab = tab;
    tab += tabSize;
    level++;
    clang_visitChildren(c, visit, nullptr);
    tab = oldTab;
    level--;
    
    //return CXChildVisit_Break;
    return CXChildVisit_Continue;
    //return CXChildVisit_Recurse;
}

int main(int argc, char* argv[])
{
    // Пока бесконтрольное переключение на файл вместо файла по умолчанию
    char* testedFile = (char*)"../tests/test000.h";
    if(argc >= 2) {
        testedFile = argv[1];
    }

    // Инициализация libclang
    CXIndex index = clang_createIndex(0, 0);
    CXTranslationUnit unit = clang_parseTranslationUnit(
        index,
        //"header.hpp", nullptr, 0,
        //"../tests/header.hpp", ullptr, 0,
        testedFile, nullptr, 0,
        nullptr, 0,
        CXTranslationUnit_None);

    // При неудачном подключении парсера
    if (unit == nullptr)
    {
        cerr << "Unable to parse translation unit. Quitting." << endl;
        exit(-1);
    }
    // Процесс пошел...
    CXCursor cursor = clang_getTranslationUnitCursor(unit);
    clang_visitChildren(cursor, visit, nullptr);

    // Завершение работы
    clang_disposeTranslationUnit(unit);
    clang_disposeIndex(index);
}
