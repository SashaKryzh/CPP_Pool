#if !defined(EX04_HPP)
#define EX04_HPP

#include <iostream>
#include <sstream>
#include <iomanip>

#include <vector>
#include <queue>
#include <stack>

#include "Token.hpp"

extern int g_token_with;

void errorExit(std::string message);

void displayTokens(std::vector<IToken *> tokens);
void displayPostfix(std::queue<IToken *> postfix);

int prec(char c);
void checkParen(std::queue<IToken *> postfix);

std::string stackToString(std::stack<Token<int>*> st);
std::string opDescription(char c);

#endif // EX04_HPP
