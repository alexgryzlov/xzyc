#include "Lex.h"

Scanner::Scanner(const std::string &text) : text_(text), pos_(0) {}

std::ostream& operator<<(std::ostream& out, const Token& token) {
    out << TokenTypeStr[static_cast<int>(token.type)] << ": " << "'" << token.lexeme << "'";
    return out;
}


Token Scanner::NextToken() {
    if (pos_ >= text_.size()) {
        return {TokenType::EndOfFile};
    }
    if (std::isdigit(text_[pos_])) {
        size_t start = pos_;
        while (std::isdigit(text_[++pos_])) {}
        return {.type = TokenType::IntegerLiteral,
                .lexeme = {&text_[start], &text_[pos_]}};
    }
    if (std::iswspace(text_[pos_])) {
        size_t start = pos_;
        while (std::iswspace(text_[++pos_])) {}
        return {.type = TokenType::Whitespace,
                .lexeme = {&text_[start], &text_[pos_]}};
    }
    switch (text_[pos_]) {
        case '+':
            return {.type = TokenType::Plus,
                    .lexeme = {&text_[pos_], &text_[++pos_]}};
        case '-':
            return {.type = TokenType::Minus,
                    .lexeme = {&text_[pos_], &text_[++pos_]}};
        case '*':
            return {.type = TokenType::Star,
                    .lexeme = {&text_[pos_], &text_[++pos_]}};
        case '/':
            return {.type = TokenType::Slash,
                    .lexeme = {&text_[pos_], &text_[++pos_]}};
        case '(':
            return {.type = TokenType::OpenParanthesis,
                    .lexeme = {&text_[pos_], &text_[++pos_]}};
        case ')':
            return {.type = TokenType::CloseParanthesis,
                    .lexeme = {&text_[pos_], &text_[++pos_]}};
        default:
            return {.type = TokenType::BadToken,
                    .lexeme = {&text_[pos_], &text_[++pos_]}};
    }
}
