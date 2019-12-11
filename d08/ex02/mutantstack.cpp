#include "mutantstack.hpp"

template <class T>
MutantStack<T>::MutantStack() {}

template <class T>
MutantStack<T>::~MutantStack() {}

template <class T>
MutantStack<T>::MutantStack(const MutantStack<T> &src)
{
    operator=(src);
}

template <class T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &src)
{
    if (this != &src)
    {
        _c = src._c;
    }
    return *this;
}

template <class T>
T &MutantStack<T>::top()
{
    return _c.front();
}

template <class T>
T const &MutantStack<T>::top() const
{
    return _c.front();
}

template <class T>
bool MutantStack<T>::empty() const
{
    return _c.empty();
}

template <class T>
typename std::list<T>::size_type MutantStack<T>::size() const
{
    return _c.size();
}

template <class T>
void MutantStack<T>::push(const T &value)
{
    _c.push_front(value);
}

template <class T>
void MutantStack<T>::pop()
{
    _c.pop_front();
}

template <class T>
typename std::list<T>::iterator MutantStack<T>::begin() { return _c.begin(); }

template <class T>
typename std::list<T>::const_iterator MutantStack<T>::begin() const { return _c.begin(); }

template <class T>
typename std::list<T>::iterator MutantStack<T>::end() { return _c.end(); }

template <class T>
typename std::list<T>::const_iterator MutantStack<T>::end() const { return _c.end(); }

template <class T>
typename std::list<T>::reverse_iterator MutantStack<T>::rbegin() { return _c.rbegin(); }

template <class T>
typename std::list<T>::const_reverse_iterator MutantStack<T>::rbegin() const { return _c.rbegin(); }

template <class T>
typename std::list<T>::reverse_iterator MutantStack<T>::rend() { return _c.rend(); }

template <class T>
typename std::list<T>::const_reverse_iterator MutantStack<T>::rend() const { return _c.rend(); }

template <class T>
MutantStack<T>::operator std::stack<T>(void)
{
    std::stack<T> stack;
    typename std::list<T>::reverse_iterator ti = _c.rbegin();
    typename std::list<T>::reverse_iterator tie = _c.rend();

    while (ti != tie)
    {
        stack.push(*ti);
        ++ti;
    }
    return (stack);
}