#include <iostream>
#include <vector>
#include <string>
#include "includes/lexer.h"

int main() {
    std::string code = "let name = \"Angassssss\"";
    std::vector<Lexer::Token> Tokens = Lexer::tokenized(code);

    for( Lexer::Token Token : Tokens) {
        printf("{ value: \"%s\" : type: %i } \n", Token.value.c_str(), Token.type);
    }
}