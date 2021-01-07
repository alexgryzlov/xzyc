#ifndef XZYC_EVALUATIONVISITOR_H
#define XZYC_EVALUATIONVISITOR_H

#include "Syntax.h"
#include "Visitor.h"

class EvaluationVisitor : public Visitor {
public:
    int Visit(const Syntax::NumberExpression* number_expression) const override;
    int Visit(const Syntax::BinaryExpression* binary_expression) const override;
};

#endif //XZYC_EVALUATIONVISITOR_H
