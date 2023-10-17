#pragma once

#include <iostream>
#include <exception>
#include <vector>
#include <cstdlib>

class Span
{
private:
	unsigned int		_maxSize;
	std::vector<int>	_array;
public:
	Span(); // Default constructor
	Span(const Span &src); // Copy constructor
	Span(unsigned int n);
	~Span(); // Destructor
	Span	&operator=(const Span &src); // Assignment operator

	// Member functions
	void	addNumber(int n);
	template <typename T>
	void	addNumbers(typename T::iterator begin, typename T::iterator end);
	void	addNumbers(int *begin, int *end);
	size_t	shortestSpan();
	size_t	longestSpan();

	class SpanFullException : public std::exception
	{
		virtual const char *what() const throw();
	};

	class SpanNotEnoughNumbersException : public std::exception
	{
		virtual const char *what() const throw();
	};
};

template <typename T>
inline void Span::addNumbers(typename T::iterator begin, typename T::iterator end)
{
	if (this->_array.size() + std::distance(begin, end) > this->_maxSize)
		throw Span::SpanFullException();
	this->_array.insert(this->_array.end(), begin, end);
}
