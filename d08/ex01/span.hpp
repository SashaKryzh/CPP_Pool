#if !defined(SPAN_HPP)
#define SPAN_HPP

#include <vector>

class Span
{
private:
    std::vector<int> _values;
    unsigned int _N;
    
public:
    Span(unsigned int);
    Span(const Span &);
    ~Span();

    Span &operator=(const Span &);

    void addNumber(int);
    void addNumber(std::vector<int>::iterator it, std::vector<int>::iterator end);

    unsigned int shortestSpan();
    unsigned int longestSpan();

    struct SpanIsFullException : public std::exception
    {
        const char *what() const throw();
    };

    struct NotEnoughValuesException : public std::exception
    {
        const char *what() const throw();
    };
};

#endif // SPAN_HPP
