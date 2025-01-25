#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>
#include <iterator>

template <typename T>
typename T::const_iterator easyfind(const T& container, int target)
{
    typename T::const_iterator it = std::find(container.begin(), container.end(), target);
    if (it == container.end()) {
        throw std::runtime_error("Value not found");
    }
    return it;
}

#endif