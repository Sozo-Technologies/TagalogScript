#include <iostream>
#include <vector>
#include <string>
#include "includes/lexer.h"

int main() {
    std::string code = "[++--]=";
    std::vector<Lexer::Token> Tokens = Lexer::tokenized(code);

    for( Lexer::Token Token : Tokens) {
        std::cout << "{ value: " << Token.value << " : type: " << Token.type << " }" << std::endl;
    }
}