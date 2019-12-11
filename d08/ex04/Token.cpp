#include "Token.hpp"

Paren::Paren(char c) : _c(c) {}

// std::ostream& operator<<(std::ostream& os, const Token<char>& dt)
// {
//     os << "Op(" << dt.getValue() << ")";
//     return os;
// }

// std::ostream& operator<<(std::ostream& os, const Token<int>& dt)
// {
//     os << "Num(" << dt.getValue() << ")";
//     return os;
// }

// std::ostream& operator<<(std::ostream& os, const Token<Paren>& dt)
// {
//     if (dt.getValue()._c == '(')
//         os << "ParOpen";
//     else
//         os << "ParClose";
//     return os;
// }