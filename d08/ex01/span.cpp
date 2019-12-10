#include "span.hpp"

Span::Span(unsigned int N) : _N(N) {}

Span::~Span() {}

Span::Span(const Span &src)
{
    operator=(src);
}

Span &Span::operator=(const Span &src)
{
    if (this != &src)
    {
        _N = src._N;
        _values = std::vector<int>(src._values.begin(), src._values.end());
    }
    return *this;
}

void Span::addNumber(int num)
{
    if (_values.size() == _N)
        throw SpanIsFullException();
    _values.push_back(num);
}

void Span::addNumber(std::vector<int>::iterator it, std::vector<int>::iterator end)
{
    for (; it != end; ++it)
        addNumber(*it);
}

unsigned int Span::shortestSpan()
{
    unsigned int shortest = UINT_MAX;
    if (_values.size() <= 1)
        throw NotEnoughValuesException();
    std::sort(_values.begin(), _values.end());
    for (std::vector<int>::iterator it = _values.begin(); it != _values.end() - 1; ++it)
    {
        unsigned int now = abs(*(it + 1) - *it);
        if (now < shortest)
            shortest = now;
    }
    return shortest;
}

unsigned int Span::longestSpan()
{
    if (_values.size() <= 1)
        throw NotEnoughValuesException();
    return *std::max_element(_values.begin(), _values.end()) - *std::min_element(_values.begin(), _values.end());
}

const char *Span::SpanIsFullException::what() const throw()
{
    return "Span is full";
}

const char *Span::NotEnoughValuesException::what() const throw()
{
    return "Not enough values to find span";
}