#include <iostream>
#include <vector>
#include <string>

#include "headers/ast.h"
#include "headers/lexer.h"

void printAST(AST::Prototype ast);

int main(int argc, char* argv[]) {
    AST::Prototype ast = AST::createPrototype("test.ph");
    printAST(ast);
}

void printAST(AST::Prototype ast) {
    for (AST::Statement statement : ast) {
        std::cout << "-------------------------------------" << '\n';
        std::cout << "Line Number: " << statement.line << '\n';
        std::cout << "NodeType: " << statement.type << '\n';
        std::cout << "Statement:" << '\n';

        std::vector<Lexer::StringyfiedToken> tokens = Lexer::tokenStringify(statement.statement);
        for (const Lexer::StringyfiedToken& token : tokens) {
            printf("{ value: \"%s\" : type: %s }\n", token.value.c_str(), token.type);
        }

        std::cout << "-------------------------------------" << '\n';
    }
}
