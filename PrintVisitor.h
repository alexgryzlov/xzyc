#ifndef XZYC_PRINTVISITOR_H
#define XZYC_PRINTVISITOR_H

#include "Visitor.h"

class PrintVisitor : public Visitor {
public:
    int Visit(const Syntax::BinaryExpression* binary_expression) const override;
    int Visit(const Syntax::NumberExpression* number_expression) const override;
};

#endif //XZYC_PRINTVISITOR_H
