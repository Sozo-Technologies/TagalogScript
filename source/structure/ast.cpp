#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include "../headers/lexer.h"
#include "../headers/ast.h"

namespace AST {

    bool isVariableDecleration_String(Lexer::Tokens tokens) {
        Lexer::Type variableDec[] = {
            Lexer::Type::StringDecleration,
            Lexer::Type::Identifier,
            Lexer::Type::Equal,
            Lexer::Type::String
        };

        for(int i = 0; i < tokens.size(); i++) {
            if(tokens[i].type != variableDec[i]) return false; 
        }

        return true;
    }

    bool isVariableDecleration_Number(Lexer::Tokens tokens) {
        Lexer::Type variableDec[] = {
            Lexer::Type::NumberDecleration,
            Lexer::Type::Identifier,
            Lexer::Type::Equal,
            Lexer::Type::Number
        };

        for(int i = 0; i < tokens.size(); i++) {
            if(tokens[i].type != variableDec[i]) return false; 
        }

        return true;
    }

    bool isEndOFLine(Lexer::Tokens tokens) {
        if(tokens.size() != 1) return false;
        return (tokens[0].type == Lexer::Type::Keyword) && (tokens[0].value == "katapusan");
    }

    bool isVariableReAssign_Number(Lexer::Tokens tokens) {
        Lexer::Type varReAss[] = {
            Lexer::Type::Identifier,
            Lexer::Type::Equal,
            Lexer::Type::Number
        };

        for(int i = 0; i < tokens.size(); i++) {
            if(tokens[i].type != varReAss[i]) return false; 
        }

        return true;
    }

    bool isVariableReAssign_String(Lexer::Tokens tokens) {
        Lexer::Type varReAss[] = {
            Lexer::Type::Identifier,
            Lexer::Type::Equal,
            Lexer::Type::String
        };

        for(int i = 0; i < tokens.size(); i++) {
            if(tokens[i].type != varReAss[i]) return false; 
        }

        return true;
    }

    AST::Type specifyType(Lexer::Tokens tokens) {

        if(tokens.empty()) 
            return AST::Type::Blank;
        if(isVariableDecleration_String(tokens) || isVariableDecleration_Number(tokens)) 
            return AST::Type::Variable_Decleration;
        if(isEndOFLine(tokens)) 
            return AST::Type::EndOFLine;

        if(isVariableReAssign_String(tokens) || isVariableReAssign_Number(tokens))
            return AST::Type::Variable_Reassign;

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