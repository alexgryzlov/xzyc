#include <iostream>
#include <string_view>
#include <vector>

#include "Lex.h"
#include "Syntax.h"
#include "Parse.h"
#include "EvaluationVisitor.h"
#include "Evaluator.h"

// Grammar:
//      term: mul {[+-] mul}
//      mul: primary {[*/] primary}
//      primary: <integer_literal> | (term)

int main() {
    std::string s;
    getline(std::cin, s);

    // Tokenizing
    Scanner scanner(s);
    std::vector<Token> tokens;
    do {
        tokens.push_back(scanner.NextToken());
    } while (tokens.back().type != TokenType::EndOfFile);
    for (auto token : tokens) {
        std::cout << token << std::endl;
    }

    // Creating AST
    Parser parser(tokens);
    auto x = parser.Parse();
    x.Print();

    // Evaluating
    Evaluator evaluator(x);
    std::cout << evaluator.Evaluate() << std::endl;
}
