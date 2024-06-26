#pragma once

#include <iostream>
#include <vector>
#include <string>

namespace Lexer {
    enum Type {
        Number,
        String,
        Boolean,
        Keywords,
        Constant,
        Identifier,
        Operator,
        Equal,
        LeftBrace,
        RightBrace,
    };

    struct Token {
        std::string value;
        Type type;
    };

    Token createToken(std::string value, Type type) {
        Token buffer;
        buffer.value = value;
        buffer.type = type;
        return buffer;
    }

    bool tokenizedSingleChars(std::vector<Token> *tokens, char c) {
        switch (c) {
            case '+' : case '-' : case '*' : case '/': {
                std::string temp(1, c);
                (*tokens).push_back(createToken(temp, Type::Operator));
                return true;
            }

            case '=' : {
                std::string temp(1, c);
                (*tokens).push_back(createToken(temp, Type::Equal));
                return true;
            }

            case '(' : case '{' : case '[' : {
                std::string temp(1, c);
                (*tokens).push_back(createToken(temp, Type::LeftBrace));
                return true;
            }

            case ')' : case '}' : case ']' : {
                std::string temp(1, c);
                (*tokens).push_back(createToken(temp, Type::LeftBrace));
                return true;
            }
        }

        return false;
    }

    std::vector<Token> tokenized(std::string source) {
        std::vector<Token> tokens;

        for(char c : source ) {
            if(tokenizedSingleChars(&tokens, c)) continue;
        }

        return tokens;
    }
}