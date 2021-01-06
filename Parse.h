#ifndef XZYC_PARSE_H
#define XZYC_PARSE_H

#include "Syntax.h"

class Parser {
public:
    Parser(const std::vector<Token>& tokens);
    Syntax::Tree Parse();

private:
    Syntax::NodePtr ParseTerm();
    Syntax::NodePtr ParseMultiplication();
    Syntax::NodePtr ParsePrimaryExpression();

private:
    Token NextToken();
    Token CurrentToken();
    Token Expect(TokenType type);

private:
    std::vector<Token> tokens_;
    size_t pos_;
};


#endif //XZYC_PARSE_H
