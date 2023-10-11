#pragma once

#include <iostream>
#include <algorithm>

template <typename T>
typename T::iterator	easyfind(T &container, int value);

class NotFoundException : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return ("Not found");
		}
};

#include "easyfind.tpp"
