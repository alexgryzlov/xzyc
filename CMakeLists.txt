project(xzyc)
set(CMAKE_CXX_STANDARD 20)
add_executable(xzyc main.cpp EvaluationVisitor.cpp Syntax.cpp Lex.cpp Parse.cpp Evaluator.cpp)