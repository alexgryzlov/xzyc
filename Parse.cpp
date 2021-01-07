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
    Syntax::NodePtr expression = ParseExpression();
    Expect(TokenType::EndOfFile);
    return Syntax::Tree(std::move(expression));
}

Syntax::NodePtr Parser::ParseExpression(int parent_precedence) {
    Syntax::NodePtr left = ParsePrimaryExpression();

    while (true) {
        int precedence = GetOperatorPrecedence(CurrentToken());
        if (precedence == 0 || precedence <= parent_precedence) {
            break;
        }
        Token op = NextToken();
        Syntax::NodePtr right = ParseExpression(GetOperatorPrecedence(op));
        left = Syntax::NodePtr(new Syntax::BinaryExpression(std::move(left), op, std::move(right)));
    }
    return left;
}

Syntax::NodePtr Parser::ParsePrimaryExpression() {
    if (CurrentToken().type == TokenType::OpenParanthesis) {
        NextToken();
        auto result = ParseExpression();
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

int Parser::GetOperatorPrecedence(const Token& token) const {
    switch (token.type) {
        case TokenType::Plus:
        case TokenType::Minus:
            return 1;
        case TokenType::Star:
        case TokenType::Slash:
            return 2;
        default:
            return 0;
    }
}
