#ifndef XZYC_SYNTAX_H
#define XZYC_SYNTAX_H

#include <string>
#include <vector>
#include <iostream>
#include <memory>

#include "Lex.h"

class EvaluationVisitor;

namespace Syntax {

    enum class NodeType {
        Integer,
        BinaryExpression
    };

    const std::string NodeTypeStr[] = {
            "<integer-node>",
            "<binary-expression-node>"
    };

    struct Node;
    using NodePtr = std::unique_ptr<Node>;

    struct Node {
        std::vector<NodePtr> children;
        virtual void Print() const = 0;
        virtual int Accept(const EvaluationVisitor* a) const = 0;
    };

    struct Expression : Node {
        Expression(Token token) : token_(token) {}
        Token GetToken() const { return token_; }
    protected:
        Token token_;
    };

    struct NumberExpression : Expression {
        NumberExpression(Token number_token) : Expression(number_token) {}
        void Print() const override;
        int Accept(const EvaluationVisitor* a) const override;
    };

    struct BinaryExpression : Expression {
        BinaryExpression(Syntax::NodePtr left,
                         Token op_token,
                         Syntax::NodePtr right) : Expression(op_token) {
            children.emplace_back(std::move(left));
            children.emplace_back(std::move(right));
        }
        void Print() const override;
        int Accept(const EvaluationVisitor* a) const override;
    };

    class Tree {
    public:
        Tree(NodePtr root) : root_(std::move(root)) {}
        void Print() {
            PrintNode(root_);
        }
        const Node* GetRoot() const { return root_.get(); }

    private:
        void PrintNode(const NodePtr& node, std::string indent = "");
        NodePtr root_;
    };
}


#endif //XZYC_SYNTAX_H
