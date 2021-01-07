#include "PrintVisitor.h"
#include "Syntax.h"

int Syntax::NumberExpression::Accept(const Visitor *a) const {
    return a->Visit(this);
}

Syntax::NumberExpression::NumberExpression(Token number_token) : Expression(number_token) {}

int Syntax::BinaryExpression::Accept(const Visitor *a) const {
    return a->Visit(this);
}

Syntax::BinaryExpression::BinaryExpression(Syntax::NodePtr left,
                                           Token op_token,
                                           Syntax::NodePtr right) : Expression(op_token) {
    children.emplace_back(std::move(left));
    children.emplace_back(std::move(right));
}

void Syntax::Tree::PrintNode(const Node* node, std::string indent) {
    std::cout << indent;
    indent += "    ";
    PrintVisitor print_visitor;
    node->Accept(&print_visitor);
    for (const auto& i : node->children) {
        PrintNode(i.get(), indent);
    }

}

void Syntax::Tree::Print()  {
    PrintNode(root_.get());
}

Syntax::Tree::Tree(Syntax::NodePtr root)  : root_(std::move(root)) {}

const Syntax::Node *Syntax::Tree::GetRoot() const  { return root_.get(); }
