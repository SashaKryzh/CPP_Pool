#ifndef EVAL_EXPR_HPP
#define EVAL_EXPR_HPP

void pop(std::stringstream &ss, float &nbr);
void pop(std::stringstream &ss, char &c);

void push(std::stringstream &ss, float nbr);
void push(std::stringstream &ss, char op);

void checkIsNumberPresent();

#endif