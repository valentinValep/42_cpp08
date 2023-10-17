#include "Span.hpp"
#include <algorithm>
#include <climits>

Span::Span(): _maxSize(0),_array() {}

Span::Span(const Span &src): _maxSize(src._maxSize), _array(src._array) {}

Span::Span(unsigned int n): _maxSize(n), _array() {}

Span::~Span() {}

Span	&Span::operator=(const Span &src)
{
	if (this == &src)
		return (*this);
	this->_maxSize = src._maxSize;
	this->_array = src._array;
	return (*this);
}

void Span::addNumber(int n)
{
	if (this->_array.size() == this->_maxSize)
		throw Span::SpanFullException();
	this->_array.push_back(n);
}

void	Span::addNumbers(int *begin, int *end)
{
	if (this->_array.size() + std::distance(begin, end) > this->_maxSize)
		throw Span::SpanFullException();
	this->_array.insert(this->_array.end(), begin, end);
}

size_t		Span::shortestSpan()
{
	size_t		min = ULONG_MAX;
	if (this->_array.size() < 2)
		throw Span::SpanNotEnoughNumbersException();
	std::sort(this->_array.begin(), this->_array.end());
	for (unsigned int i = 0; i < this->_array.size() - 1; i++)
	{
		if ((size_t)this->_array[i + 1] - this->_array[i] < min)
			min = this->_array[i + 1] - this->_array[i];
	}
	return (min);
}

size_t		Span::longestSpan()
{
	if (this->_array.size() < 2)
		throw Span::SpanNotEnoughNumbersException();
	return (std::max_element(this->_array.begin(), this->_array.end())[0] - std::min_element(this->_array.begin(), this->_array.end())[0]);
}

const char *Span::SpanFullException::what() const throw()
{
	return ("Span is full");
}

const char *Span::SpanNotEnoughNumbersException::what() const throw()
{
	return ("Not enough numbers in Span");
}
