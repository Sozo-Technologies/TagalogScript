#include <iostream>
#include <vector>
#include <string>
#include "../includes/lexer.h"

bool tokenizedSingleChars(std::vector<Lexer::Token> *tokens, char c);

namespace Lexer {
    enum Type {
        Number,
        String,
        Boolean,
        Keywords,
        Constant,
        Identifiers,
        Operators
    };

    typedef struct Token {
        const char* value;
        Type type;
    };

    Token createToken(const char* value, Type type) {
        Token buffer;
        buffer.value = value;
        buffer.type = type;
        
        return buffer;
    }

    std::vector<Token> tokenized(std::string source) {
        std::vector<Token> tokens;

        for(char c : source ) {
            if(tokenizedSingleChars(&tokens, c)) return;

            std::cout << "Done" << std::endl;
        }

        return tokens;
    }
    
}

bool tokenizedSingleChars(std::vector<Lexer::Token> *tokens, char c) {
    switch (c) {
        case '+':
        case '-':
        case '*':
        case '/': {
            std::string temp(1, c);
            (*tokens).push_back(Lexer::createToken(temp.c_str(), Lexer::Type::Operators));
            return true;
        }
        default:
            return false;
    }
}