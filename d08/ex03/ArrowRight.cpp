#include "IInstruction.hpp"

IInstruction::IInstruction(char c) : _c(c){};

char IInstruction::getChar() const
{
    return _c;
}

ArrowRight::ArrowRight() : IInstruction('>') {}
ArrowRight::~ArrowRight() {}
ArrowRight::ArrowRight(const ArrowRight &s) : IInstruction(s.getChar()) {}
ArrowRight &ArrowRight::operator=(const ArrowRight &) { return *this; }
void ArrowRight::execute(char arr[], int &idx, std::vector<IInstruction *> v, unsigned long &i) const
{
    static_cast<void>(i);
    static_cast<void>(v);
    static_cast<void>(arr);
    idx++;
}

ArrowLeft::ArrowLeft() : IInstruction('<') {}
ArrowLeft::~ArrowLeft() {}
ArrowLeft::ArrowLeft(const ArrowLeft &s) : IInstruction(s.getChar()) {}
ArrowLeft &ArrowLeft::operator=(const ArrowLeft &) { return *this; }
void ArrowLeft::execute(char arr[], int &idx, std::vector<IInstruction *> v, unsigned long &i) const
{
    static_cast<void>(i);
    static_cast<void>(arr);
    static_cast<void>(v);
    idx--;
}

Plus::Plus() : IInstruction('+') {}
Plus::~Plus() {}
Plus::Plus(const Plus &s) : IInstruction(s.getChar()) {}
Plus &Plus::operator=(const Plus &) { return *this; }
void Plus::execute(char arr[], int &idx, std::vector<IInstruction *> v, unsigned long &i) const
{
    static_cast<void>(i);
    static_cast<void>(v);
    arr[idx]++;
}

Minus::Minus() : IInstruction('-') {}
Minus::~Minus() {}
Minus::Minus(const Minus &s) : IInstruction(s.getChar()) {}
Minus &Minus::operator=(const Minus &) { return *this; }
void Minus::execute(char arr[], int &idx, std::vector<IInstruction *> v, unsigned long &i) const
{
    arr[idx]--;
    static_cast<void>(v);
    static_cast<void>(i);
}

#include <iostream>

Dot::Dot() : IInstruction('.')
{
}
Dot::~Dot() {}
Dot::Dot(const Dot &s) : IInstruction(s.getChar()) {}
Dot &Dot::operator=(const Dot &) { return *this; }
void Dot::execute(char arr[], int &idx, std::vector<IInstruction *> v, unsigned long &i) const
{
    static_cast<void>(i);
    static_cast<void>(v);
    std::cout << arr[idx];
}

Comma::Comma() : IInstruction(',') {}
Comma::~Comma() {}
Comma::Comma(const Comma &s) : IInstruction(s.getChar()) {}
Comma &Comma::operator=(const Comma &) { return *this; }
void Comma::execute(char arr[], int &idx, std::vector<IInstruction *> v, unsigned long &i) const
{
    std::cin >> arr[idx];
    static_cast<void>(i);
    static_cast<void>(v);
}

BraceRight::BraceRight() : IInstruction('[') {}
BraceRight::~BraceRight() {}
BraceRight::BraceRight(const BraceRight &s) : IInstruction(s.getChar()) {}
BraceRight &BraceRight::operator=(const BraceRight &) { return *this; }
void BraceRight::execute(char arr[], int &idx, std::vector<IInstruction *> v, unsigned long &i) const
{
    int brc = 1;

    if (arr[idx] == 0)
    {
        while (brc)
        {
            i++;
            if (dynamic_cast<BraceRight *>(v[i]))
                brc++;
            if (dynamic_cast<BraceLeft *>(v[i]))
                brc--;
        }
    }
}

BraceLeft::BraceLeft() : IInstruction(']') {}
BraceLeft::~BraceLeft() {}
BraceLeft::BraceLeft(const BraceLeft &s) : IInstruction(s.getChar()) {}
BraceLeft &BraceLeft::operator=(const BraceLeft &) { return *this; }
void BraceLeft::execute(char arr[], int &idx, std::vector<IInstruction *> v, unsigned long &i) const
{
    int brc = 1;

    if (arr[idx])
    {
        while (brc)
        {
            i--;
            if (dynamic_cast<BraceLeft *>(v[i]))
                brc++;
            if (dynamic_cast<BraceRight *>(v[i]))
                brc--;
        }
        i--;
    }
}