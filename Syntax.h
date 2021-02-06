#ifndef XZYC_SYNTAX_H
#define XZYC_SYNTAX_H

#include <string>
#include <vector>
#include <iostream>
#include <memory>

#include "Lex.h"

class Visitor;

namespace Syntax {

    struct Node;
    using NodePtr = std::unique_ptr<Node>;

    struct Node {
        std::vector<NodePtr> children;
        virtual int Accept(const Visitor* a) const = 0;
    };

    struct Expression : Node {
        Expression(Token token) : token_(token) {}
        Token GetToken() const { return token_; }
    protected:
        Token token_;
    };

    struct NumberExpression : Expression {
        NumberExpression(Token number_token);
        int Accept(const Visitor* a) const override;
    };

    struct BinaryExpression : Expression {
        BinaryExpression(Syntax::NodePtr left,
                         Token op_token,
                         Syntax::NodePtr right);
        int Accept(const Visitor* a) const override;
    };

    class Tree {
    public:
        Tree(NodePtr root);
        void Print();
        const Node* GetRoot() const;

    private:
        void PrintNode(const Node* node, std::string indent = "");
        NodePtr root_;
    };
}


#endif //XZYC_SYNTAX_H
