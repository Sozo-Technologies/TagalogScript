#pragma once

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include "lexer.h"

namespace AST {
    enum Type {
        Variable_Decleration,
        Function_Declearion,
        EndOFLine,
        Function_Call,
        Variable_Reassign,
        Loop_Decleration,
        WhileLoop_Delcleration,
        IF_Decleration,
        IF_ELSE_Decleration,
        Blank,
        Imports,
        Unknown
    };

    struct Statement {
        AST::Type type;
        int line;
        std::vector<Lexer::Token> statement;
    };

    typedef std::vector<AST::Statement> Prototype;

    Prototype createPrototype(const char* target);
}