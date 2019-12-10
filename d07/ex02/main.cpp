#include <iostream>

#include "Array.hpp"

template <class T>
void displayArray(Array<T> a)
{
    for (size_t i = 0; i < a.size(); i++)
    {
        std::cout << a[i] << std::endl;
    }
}

int main()
{
    Array<int> a(10);
    displayArray(a);

    std::cout << "\n--- Rand() ---\n";
    srand(time(NULL));
    for (size_t i = 0; i < a.size(); i++)
    {
        a[i] = rand() % 100;
    }

    displayArray(a);

    Array<int> b(5);
    displayArray(b);
    b = a;
    a[0] = 666;
    displayArray(b);

    Array<int> c(b);
    displayArray(c);

    // system("leaks -q array");
    return 0;
}