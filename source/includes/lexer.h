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
        Boolean,
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

    std::vector<Token> tokenized(std::string source);
}

#endif