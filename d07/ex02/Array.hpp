#if !defined(ARRAY_HPP)
#define ARRAY_HPP

template<class T>
class Array
{
private:
    T *_a;
    unsigned int _n;

public:
    Array();
    Array(unsigned int n);
    ~Array();

    Array(const Array &);

    Array &operator=(const Array &);
    T &operator[] (int); 

    unsigned int size() const;

    struct OutOfBounds : public std::exception
    {
        const char *what() const throw();
    };
};

#include "Array.ipp"

#endif // ARRAY_HPP
