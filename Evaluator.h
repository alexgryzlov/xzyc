#ifndef XZYC_EVALUATOR_H
#define XZYC_EVALUATOR_H

#include "Syntax.h"

class Evaluator {
public:
    Evaluator(const Syntax::Tree& tree);
    int Evaluate();

private:
    const Syntax::Node* root_;
};

#endif //XZYC_EVALUATOR_H
