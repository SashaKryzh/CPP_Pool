#include <iostream>

template <class T>
void swap(T &a, T &b)
{
    T tmp;
    tmp = b;
    b = a;
    a = tmp;
}

template <class T>
T &min(T &a, T &b)
{
    return a < b ? a : b;
}

template <class T>
T &max(T &a, T &b)
{
    return a > b ? a : b;
}

int main()
{
    std::cout << "SWAP\n\n";
    {
        int a = 5;
        int b = 10;

        std::cout << a << " " << b << std::endl;
        swap(a, b);
        std::cout << a << " " << b << std::endl;
    }
    {
        char a = 'a';
        char b = 'b';

        std::cout << a << " " << b << std::endl;
        swap(a, b);
        std::cout << a << " " << b << std::endl;
    }
    {
        std::string a = "first";
        std::string b = "second";

        std::cout << a << " " << b << std::endl;
        swap(a, b);
        std::cout << a << " " << b << std::endl;
    }

    std::cout << "\nMAX / MIN\n\n";
    {
        int a = 5;
        int b = 10;

        std::cout << a << " " << b << std::endl;
        std::cout << "min: " << min(a, b) << std::endl;
        std::cout << "max: " << max(a, b) << std::endl;
    }
    {
        int a = 5;
        int b = 5;

        std::cout << a << " " << b << std::endl;
        std::cout << "min: " << min(a, b) << std::endl;
        std::cout << "max: " << max(a, b) << std::endl;
    }
    {
        std::string a = "aaa";
        std::string b = "bbb";

        std::cout << a << " " << b << std::endl;
        std::cout << "min: " << min(a, b) << std::endl;
        std::cout << "max: " << max(a, b) << std::endl;
    }

    std::cout << "\nFrom Subject\n\n";

    int a = 2;
    int b = 3;
    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
    std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
    std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;

    return 0;
}