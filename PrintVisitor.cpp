#include "PrintVisitor.h"

int PrintVisitor::Visit(const Syntax::BinaryExpression *binary_expression) const {
    std::cout << "<binary-expression> : " << binary_expression->GetToken().lexeme << std::endl;
}

int PrintVisitor::Visit(const Syntax::NumberExpression *number_expression) const {
    std::cout << "<number-expression> : " << number_expression->GetToken().lexeme << std::endl;
}
