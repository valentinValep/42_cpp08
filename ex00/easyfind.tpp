#include "easyfind.hpp"

template <typename T>
typename T::iterator	easyfind(T &container, int value)
{
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw NotFoundException();
	return (it);
}

const char *NotFoundException::what() const throw()
{
	return "Value not found in container";
}
