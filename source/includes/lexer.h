#pragma once

#ifndef LEXER_H
#define LEXER_H

#include <iostream>
#include <vector>
#include <string>

namespace Lexer {
    enum Type {
        Number,
        String,
        NumberDecleration,
        StringDecleration,
        Keyword,
        Constant,
        Identifier,
        Operator,
        Equal,
        LeftBrace,
        RightBrace,
        Unknown
    };

    struct Token {
        std::string value;
        Type type;
    };

    struct StringyfiedToken {
        std::string value;
        const char* type;
    };

    std::vector<Token> tokenized(std::string source);
    std::vector<StringyfiedToken> tokenStringify(std::vector<Token> tokens);
}

#endif