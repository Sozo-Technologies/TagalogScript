#pragma once

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
        FunctionDecleration,
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

    typedef std::vector<Token> Tokens;
    typedef std::vector<StringyfiedToken> StringedTokens;

    Tokens tokenized(std::string source);
    StringedTokens tokenStringify(Tokens tokens);
}