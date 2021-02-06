#ifndef XZYC_LEX_H
#define XZYC_LEX_H

#include <iostream>

enum class TokenType {
    Plus,
    Minus,
    Star,
    Slash,
    IntegerLiteral,
    Whitespace,
    OpenParanthesis,
    CloseParanthesis,
    EndOfFile,
    BadToken
};

const std::string TokenTypeStr[] = {
        "<plus>",
        "<minus>",
        "<star>",
        "<slash>",
        "<integer_literal>",
        "<whitespace>",
        "<open_paranthesis>",
        "<close_paranthesis>",
        "<EOF>",
        "<bad_token>"
};

struct Token {
    TokenType type;
    std::string_view lexeme;
};



class Scanner {
public:
    Scanner(const std::string& text);
    Token NextToken();

private:
    const std::string& text_;
    size_t pos_;
};

std::ostream& operator<<(std::ostream& out, const Token& token);

#endif //XZYC_LEX_H
