#include <iostream>
#include <vector>

#include "easyfind.hpp"

template<typename T>
void lookFor(std::vector<T> &arr, int look)
{
    typename std::vector<T>::iterator res = easyfind(arr, look);
    if (res != arr.end())
        std::cout << *res << std::endl;
    else
        std::cout << "Not found" << std::endl;
}

int main()
{
    std::vector<int> a;
    
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    a.push_back(5);

    lookFor(a, 1);
    lookFor(a, 3);
    lookFor(a, 6);

    std::vector<char> c;

    c.push_back('a');
    c.push_back('b');
    c.push_back('c');
    c.push_back('d');
    c.push_back('e');

    lookFor(c, 'a');
    lookFor(c, 'c');
    lookFor(c, 'z');

    return 0;
}