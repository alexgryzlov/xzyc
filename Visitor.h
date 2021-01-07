#ifndef XZYC_VISITOR_H
#define XZYC_VISITOR_H

#include "Syntax.h"

class Visitor {
public:
    virtual int Visit(const Syntax::NumberExpression*) const = 0;
    virtual int Visit(const Syntax::BinaryExpression*) const = 0;
};

#endif //XZYC_VISITOR_H
