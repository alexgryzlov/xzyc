#include "Parse.h"

Parser::Parser(const std::vector<Token> &tokens)  : pos_(0) {
    for (const auto& token : tokens) {
        if (token.type != TokenType::BadToken &&
            token.type != TokenType::Whitespace) {
            tokens_.push_back(token);
        }
    }
}

Syntax::Tree Parser::Parse() {
    Syntax::NodePtr expression = ParseTerm();
    Expect(TokenType::EndOfFile);
    return Syntax::Tree(std::move(expression));
}

Syntax::NodePtr Parser::ParseTerm() {
    Syntax::NodePtr left = ParseMultiplication();

    while (CurrentToken().type == TokenType::Plus ||
           CurrentToken().type == TokenType::Minus) {
        Token op = NextToken();
        Syntax::NodePtr right = ParseMultiplication();
        left = Syntax::NodePtr(new Syntax::BinaryExpression(std::move(left), op, std::move(right)));
    }
    return left;
}

Syntax::NodePtr Parser::ParseMultiplication() {
    Syntax::NodePtr left = ParsePrimaryExpression();

    while (CurrentToken().type == TokenType::Star ||
           CurrentToken().type == TokenType::Slash) {
        Token op = NextToken();
        Syntax::NodePtr right = ParsePrimaryExpression();
        left = Syntax::NodePtr(new Syntax::BinaryExpression(std::move(left), op, std::move(right)));
    }
    return left;
}

Syntax::NodePtr Parser::ParsePrimaryExpression() {
    if (CurrentToken().type == TokenType::OpenParanthesis) {
        NextToken();
        auto result = ParseTerm();
        Expect(TokenType::CloseParanthesis);
        return result;
    }
    auto number_token = Expect(TokenType::IntegerLiteral);
    return Syntax::NodePtr(new Syntax::NumberExpression(number_token));
}

Token Parser::NextToken() {
    return tokens_[pos_++];
}

Token Parser::CurrentToken() {
    return tokens_[pos_];
}

Token Parser::Expect(TokenType type) {
    if (CurrentToken().type == type) {
        return NextToken();
    }
    // Throw error
    std::cout << "Something went wrong!" << std::endl;
    return Token{.type = TokenType::BadToken,
            .lexeme = {}};
}
