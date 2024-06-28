#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "../headers/lexer.h"


std::map<std::string, Lexer::Type> defineKeyWords() {
    std::map<std::string, Lexer::Type> tokens;

    //Decleration
    tokens["textong"] = Lexer::StringDecleration;
    tokens["numerong"] = Lexer::NumberDecleration;

    //Assignment
    tokens["bilang"] = Lexer::Equal;

    tokens["let"] = Lexer::Keyword;
    tokens["const"] = Lexer::Constant;

    //Loop
    tokens["para"] = Lexer::Keyword;
    tokens["sa"] = Lexer::Keyword;
    tokens["mula"] = Lexer::Equal;
    tokens["hanggang"] = Lexer::Keyword;

    //Function
    tokens["pamamaraan"] = Lexer::FunctionDecleration;
    tokens["na"] = Lexer::Keyword;
    tokens["namayroong"] = Lexer::Keyword;
    tokens["at"] = Lexer::Keyword;

    //End
    tokens["katapusan"] = Lexer::Keyword;

    return tokens;
}
std::map<std::string, Lexer::Type> Keywords = defineKeyWords();

namespace Lexer {

    Token createToken(std::string value, Type type) {
        Token token;
        token.value = value;
        token.type = type;
        return token;
    }

    bool tokenizedSingleChars(std::vector<Token> *tokens, char c) {
        switch (c) {
            case '+': case '-': case '*': case '/': {
                std::string temp(1, c);
                tokens->push_back(createToken(temp, Type::Operator));
                return true;
            }
            case '=': {
                std::string temp(1, c);
                tokens->push_back(createToken(temp, Type::Equal));
                return true;
            }
            case '(': case '{': case '[': {
                std::string temp(1, c);
                tokens->push_back(createToken(temp, Type::LeftBrace));
                return true;
            }
            case ':': {
                std::string temp(1, c);
                tokens->push_back(createToken(temp, Type::Keyword));
                return true;
            }
            case ')': case '}': case ']': {
                std::string temp(1, c);
                tokens->push_back(createToken(temp, Type::RightBrace));
                return true;
            }
        }
        return false;
    }

    bool isAlphabet(const std::string& str) {
        for (char c : str) {
            if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))) {
                return false;
            }
        }
        return true;
    }

    bool isInteger(const std::string& str) {
        for (char c : str) {
            if (!(c >= '0' && c <= '9')) {
                return false;
            }
        }
        return true;
    }

    bool tokenizedMultiChars(std::vector<Token> *tokens, const std::string& source, size_t &index) {
        std::string buffer;
        char currentChar = source[index];

        while (index < source.size() && std::isspace(currentChar)) {
            index++;
            if (index < source.size()) {
                currentChar = source[index];
            }
        }

        if (currentChar == '"') {
            buffer += currentChar;
            index++;
            if (index < source.size()) {
                currentChar = source[index];
            }

            while (index < source.size() && currentChar != '"') {
                buffer += currentChar;
                index++;
                if (index < source.size()) {
                    currentChar = source[index];
                }
            }

            if (index < source.size() && currentChar == '"') {
                buffer += currentChar;
                index++;
            }

            tokens->push_back(createToken(buffer, Type::String));
            return true;
        }

        while (index < source.size() && (std::isalpha(currentChar) || std::isdigit(currentChar))) {
            buffer += currentChar;
            index++;
            if (index < source.size()) {
                currentChar = source[index];
            }
        }

        if (!buffer.empty()) {
            auto it = Keywords.find(buffer);
            if (it != Keywords.end()) {
                tokens->push_back(createToken(buffer, it->second));
            } else if (isInteger(buffer)) {
                tokens->push_back(createToken(buffer, Type::Number));
            } else if (isAlphabet(buffer)) {
                tokens->push_back(createToken(buffer, Type::Identifier));
            } else {
                tokens->push_back(createToken(buffer, Type::Unknown));
            }
            return true;
        }

        return false;
    }


    std::vector<Token> tokenized(std::string source) {
        

        std::vector<Token> tokens;
        size_t index = 0;
        
        while (index < source.size()) {
            if (tokenizedSingleChars(&tokens, source[index])) {
                index++;
            } else if (tokenizedMultiChars(&tokens, source, index)) {
                index++;
            } else {
                index++;
            }
        }
        return tokens;
    }

    std::vector<StringyfiedToken> tokenStringify(std::vector<Token> tokens) {
        const char* strtoken[] = {
            "Number",
            "String",
            "NumberDecleration",
            "StringDecleration",
            "Keyword",
            "Constant",
            "Identifier",
            "Operator",
            "Equal",
            "LeftBrace",
            "RightBrace",
            "FunctionDecleration",
            "Unknown"
        };
        std::vector<StringyfiedToken> strToken;

        for(size_t i = 0; i < tokens.size(); i++ ) {
            StringyfiedToken buffer;
            buffer.value = tokens[i].value;
            buffer.type = strtoken[tokens[i].type];
            strToken.push_back(buffer);
        }

        return strToken;
    }
}