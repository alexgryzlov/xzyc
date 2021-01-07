#ifndef XZYC_PARSE_H
#define XZYC_PARSE_H

#include "Syntax.h"

class Parser {
public:
    Parser(const std::vector<Token>& tokens);
    Syntax::Tree Parse();

private:
    Syntax::NodePtr ParseExpression(int parent_precedence = 0);
    Syntax::NodePtr ParsePrimaryExpression();

private:
    Token NextToken();
    Token CurrentToken();
    Token Expect(TokenType);
    int GetOperatorPrecedence(const Token&) const;

private:
    std::vector<Token> tokens_;
    size_t pos_;
};


#endif //XZYC_PARSE_H
