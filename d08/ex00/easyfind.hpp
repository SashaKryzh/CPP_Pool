#if !defined(EASY_FIND_HPP)
#define EASY_FIND_HPP

#include <algorithm>

template<typename T>
typename T::iterator easyfind(T &a, int find)
{
    return std::find(a.begin(), a.end(), find);
}

#endif // EASY_FIND_HPP
