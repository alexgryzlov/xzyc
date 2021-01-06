#include "EvaluationVisitor.h"
#include "Syntax.h"


int Syntax::NumberExpression::Accept(const EvaluationVisitor *a) const {
    return a->Visit(this);
}

void Syntax::NumberExpression::Print() const {
    std::cout << "<number-expression> : " << token_.lexeme << std::endl;
}

int Syntax::BinaryExpression::Accept(const EvaluationVisitor *a) const {
    return a->Visit(this);
}

void Syntax::BinaryExpression::Print() const {
    std::cout << "<binary-expression> : " << token_.lexeme << std::endl;
}

void Syntax::Tree::PrintNode(const Syntax::NodePtr &node, std::string indent) {
    std::cout << indent;
    indent += "    ";
    node->Print();
    for (const auto& i : node->children) {
        PrintNode(i, indent);
    }

}
