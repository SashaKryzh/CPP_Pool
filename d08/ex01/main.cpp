#include <iostream>

#include "span.hpp"

int main()
{
    try
    {
        Span s1(1);
        s1.addNumber(4);
        s1.addNumber(2);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    Span sp = Span(5);
    sp.addNumber(5);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    Span s2(42000);
    std::vector<int> source;
    for (int i = 666; i < 42666; ++i)
        source.push_back(i);
    s2.addNumber(source.begin(), source.end());
    std::cout << s2.shortestSpan() << std::endl;
    std::cout << s2.longestSpan() << std::endl;

    try
    {
        Span s3(10);
        std::vector<int> source;
        for (int i = 0; i < 11; ++i)
            source.push_back(i);
        s3.addNumber(source.begin(), source.end());
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        Span s3(10);
        std::cout << s3.shortestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}