#include <iostream>

template <class T>
void iter(T *a, size_t n, void (*f)(T &))
{
    for (size_t i = 0; i < n; i++)
    {
        (*f)(a[i]);
    }
}

template <class T>
void print(T &e)
{
    std::cout << e << std::endl;
}

int main()
{
    char a[5] = {'a', 'b', 'c', 'd', 'e'};
    int b[5] = {1, 2, 3, 4, 5};
    std::string c[3] = {"I Want", "to", "Break Free!"};

    iter<char>(a, 5, print);
    std::cout << "\n";
    iter<int>(b, 5, print);
    std::cout << "\n";
    iter<std::string>(c, 3, print);

    return 0;
}