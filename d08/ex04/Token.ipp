// #ifndef T_HPP
// #define T_HPP

// #include "Token.hpp"

// template <typename T>
// Token<T>::Token(T value) : _value(value) {}

// template <typename T>
// Token<T>::~Token() {}

// template <typename T>
// Token<T>::Token(const Token<T> &src)
// {
//     operator=(src);
// }

// template <typename T>
// Token<T> &Token<T>::operator=(const Token<T> &src)
// {
//     if (this != &src)
//     {
//         _value = src._value;
//     }
//     return *this;
// }

// template <typename T>
// T Token<T>::getValue() const
// {
//     return _value;
// }

// template <>
// class Token<char>
// {
//     std::string toString() const
//     {
//         return "Op(" + getValue() + ")";
//     }
// };

// // template<>
// // std::string Token<int>::toString() const
// // {
// //     return "Op("; //+ _value + ")";
// // }

// // template<>
// // std::string Token<Paren>::toString() const
// // {
// //     if (_value._c == '(')
// //         return "ParOpen";
// //     else
// //         return "ParClose";
// // }

// #endif