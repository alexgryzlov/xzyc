#include <charconv>

#include "EvaluationVisitor.h"

int EvaluationVisitor::Visit(const Syntax::BinaryExpression *binary_expression) const {
    int left = binary_expression->children[0]->Accept(this);
    int right = binary_expression->children[1]->Accept(this);
    switch (binary_expression->GetToken().type) {
        case TokenType::Plus:
            return left + right;
        case TokenType::Minus:
            return left - right;
        case TokenType::Star:
            return left * right;
        case TokenType::Slash:
            return left / right;
    }
}

int EvaluationVisitor::Visit(const Syntax::NumberExpression *number_expression) const {
    int number;
    std::from_chars(number_expression->GetToken().lexeme.begin(),
                    number_expression->GetToken().lexeme.end(),
                    number);
    return number;
}
