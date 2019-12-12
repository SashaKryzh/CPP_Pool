#if !defined(EX04_HPP)
#define EX04_HPP

#include <iostream>

#include <vector>
#include <queue>
#include <stack>

#include "Token.hpp"

void errorExit(std::string message);

void displayTokens(std::vector<IToken *> tokens);
void displayPostfix(std::queue<IToken *> postfix);

int prec(char c);

#endif // EX04_HPP
