#if !defined(ARRAY_IPP)
#define ARRAY_IPP

#include "Array.hpp"

template <class T>
Array<T>::Array() : _a(nullptr), _n(0) {}

template <class T>
Array<T>::Array(unsigned int n)
{
    _n = n;
    if (_n != 0)
        _a = new T[_n];
    for (size_t i = 0; i < _n; i++)
        _a[i] = 0;
}

template <class T>
Array<T>::~Array()
{
    delete[] _a;
}

template <class T>
Array<T>::Array(const Array<T> &src) : _a(nullptr), _n(0)
{
    operator=(src);
}

template <class T>
Array<T> &Array<T>::operator=(const Array<T> &src)
{
    if (this != &src)
    {
        if (_a != nullptr)
            delete [] _a;
        _n = src._n;
        if (_n != 0)
        {
            _a = new T[_n];
            for (size_t i = 0; i < _n; i++)
            {
                _a[i] = src._a[i];
            }
        }
    }
    return *this;
}

template <class T>
T &Array<T>::operator[](int idx)
{
    if (idx < 0 || static_cast<unsigned int>(idx) > _n)
        throw OutOfBounds();
    return _a[idx];
}

template <class T>
unsigned int Array<T>::size() const
{
    return _n;
}

template <class T>
const char *Array<T>::OutOfBounds::what() const throw()
{
    return "Index out of bounds exception";
}

#endif // ARRAY_IPP