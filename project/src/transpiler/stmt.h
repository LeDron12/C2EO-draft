#ifndef __STMTL__
#define __STMTL__

// Заголовочный файл с описаниемо ператоров

// Declares clang::SyntaxOnlyAction.
#include "clang/Frontend/FrontendActions.h"
#include "clang/Tooling/CommonOptionsParser.h"
#include "clang/Tooling/Tooling.h"

// Declares llvm::cl::extrahelp.
#include "llvm/Support/CommandLine.h"

#include "clang/ASTMatchers/ASTMatchers.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"

#include "clang/AST/ASTContext.h"

using namespace clang::tooling;
using namespace llvm;
using namespace clang;
using namespace clang::ast_matchers;


using namespace clang;

//-------------------------------------------------------------------------------------------------

// Определение и тестовый вывод основных параметров составного оператора
void getCompoundStmtParameters(const CompoundStmt* CS, int shift = 0);

// Анализ полученного начального значения с последующим использованием
//void initValueAnalysis(const VarDecl *VD, std::string &str);


// Анализ типа для неициализированных переменны с установко нулевого значения
//void initZeroValueAnalysis(const VarDecl *VD, std::string &str);

#endif // __STMTL__
