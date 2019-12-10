#if !defined(MUTANT_STACK_HPP)
#define MUTANT_STACK_HPP

#include <algorithm>
#include <list>
#include <stack>

template <class T>
class MutantStack
{
public:
    typedef typename std::list<T>::iterator iterator;

private:
    std::list<T> _c;

public:
    MutantStack();
    ~MutantStack();

    MutantStack(const MutantStack<T> &);
    MutantStack<T> &operator=(const MutantStack<T> &);

    T &top();
    T const &top() const;

    bool empty() const;
    typename std::list<T>::size_type size() const;

    void push(const T &value);
    void pop();

    typename std::list<T>::iterator begin();
    typename std::list<T>::const_iterator begin() const;
    typename std::list<T>::iterator end();
    typename std::list<T>::const_iterator end() const;

    typename std::list<T>::reverse_iterator rbegin();
    typename std::list<T>::const_reverse_iterator rbegin() const;
    typename std::list<T>::reverse_iterator rend();
    typename std::list<T>::const_reverse_iterator rend() const;

    operator std::stack<T>(void);
};

#include "mutantstack.cpp"

#endif // MUTANT_STACK_HPP
