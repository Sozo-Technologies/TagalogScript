#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include "../headers/lexer.h"
#include "../headers/ast.h"

namespace AST {

    AST::Type specifyType(Lexer::Tokens tokens) {

        if(tokens.empty()) return AST::Type::Blank;

        return AST::Type::Unknown;
    }

    AST::Statement createStatement(int line, std::string source) {
        AST::Statement buffer;
        Lexer::Tokens statement = Lexer::tokenized(source);
        buffer.type = specifyType(statement);
        buffer.line = line;
        buffer.statement = statement;
        return buffer;
    }

    Prototype createPrototype(const char* target) {
        std::vector<AST::Statement> buffer;

        std::ifstream infile(target);

        int line_number = 0;

        if(infile.is_open()) {
            std::string line;
            while(getline(infile,line)) {
                line_number++;
                buffer.push_back(createStatement(line_number, line));
            }
            infile.close();
        }else {
            std::cerr << "Error Reading the File" << std::endl;
        }
        return buffer;
    }
}