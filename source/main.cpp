#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "includes/lexer.h"

std::string getSourceCode(const char* target);

int main(int argc, char* argv[]) {

    std::string source_code = getSourceCode("test.ph");
    std::vector<Lexer::Token> Tokens = Lexer::tokenized(source_code);
    std::vector<Lexer::StringyfiedToken> stringifyToken = Lexer::tokenStringify(Tokens);

    for( Lexer::StringyfiedToken Token : stringifyToken) {
        printf("{ value: \"%s\" : type: %s } \n", Token.value.c_str(), Token.type);
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