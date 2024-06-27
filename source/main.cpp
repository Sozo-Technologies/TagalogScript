#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "includes/lexer.h"

std::string getSourceCode(const char* target);

int main() {

    std::string source_code = getSourceCode("test.ph");
    std::vector<Lexer::Token> Tokens = Lexer::tokenized(source_code);

    for( Lexer::Token Token : Tokens) {
        printf("{ value: \"%s\" : type: %i } \n", Token.value.c_str(), Token.type);
    }
}

std::string getSourceCode(const char* target) {
    std::string buffer;

    std::ifstream infile(target);
    if(infile.is_open()) {
        std::string line;
        while(getline(infile,line)) {
            buffer += line + '\n';
        }
        infile.close();
    }else {
        std::cerr << "Error Reading the File" << std::endl;
    }

    return buffer;
}