#include "Evaluator.h"
#include "EvaluationVisitor.h"

int Evaluator::Evaluate() {
    EvaluationVisitor visitor;
    return root_->Accept(&visitor);
}

Evaluator::Evaluator(const Syntax::Tree &tree)  {
    root_ = tree.GetRoot();
}
