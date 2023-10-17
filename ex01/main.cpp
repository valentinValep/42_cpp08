#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <vector>

int	construction_tests()
{
	// Default constructor
	Span sp;

	try
	{
		sp.shortestSpan();
		std::cerr << __FILE__ << ":" << __LINE__ << ": " << "shortestSpan Span method should throw an exception" << '\n';
		return (1);
	}
	catch(const std::exception& e) {}

	try
	{
		sp.longestSpan();
		std::cerr << __FILE__ << ":" << __LINE__ << ": " << "longestSpan Span method should throw an exception" << '\n';
		return (1);
	}
	catch(const std::exception& e) {}

	try
	{
		sp.addNumber(42);
		std::cerr << __FILE__ << ":" << __LINE__ << ": " << "addNumber Span method should throw an exception" << '\n';
		return (1);
	}
	catch(const std::exception& e) {}

	try
	{
		sp.addNumbers<std::vector<int> >(std::vector<int>(10, 42).begin(), std::vector<int>(10, 42).end());
		std::cerr << __FILE__ << ":" << __LINE__ << ": " << "addNumbers Span method should throw an exception" << '\n';
		return (1);
	}
	catch(const std::exception& e) {}

	// Constructor with size

	Span sp3 = Span(2);

	sp3.addNumber(42);
	sp3.addNumber(42);

	try
	{
		sp3.addNumber(42);
		std::cerr << __FILE__ << ":" << __LINE__ << ": " << "addNumber Span method should throw an exception" << '\n';
		return (1);
	}
	catch(const std::exception& e) {}


	// Copy constructor
	sp = Span(5);

	sp.addNumber(6);

	Span sp2 = sp;

	sp.addNumber(3);

	try
	{
		sp2.shortestSpan();
		std::cerr << __FILE__ << ":" << __LINE__ << ": " << "shortestSpan Span method should throw an exception" << '\n';
		return (1);
	}
	catch(const std::exception& e) {}

	if (sp.shortestSpan() != 3)
	{
		std::cout << __FILE__ << ":" << __LINE__ << ": " << "shortestSpan() should return 3" << std::endl;
		return (1);
	}

	// Assignment operator

	sp2.addNumber(17);

	sp = sp2;

	if (sp.shortestSpan() != 17 - 6)
	{
		std::cout << __FILE__ << ":" << __LINE__ << ": " << "shortestSpan() should return 11" << std::endl;
		return (1);
	}

	return (0);
}

int	basic_tests()
{
	Span sp = Span(5);

	try
	{
		sp.shortestSpan();
		std::cerr << __FILE__ << ":" << __LINE__ << ": " << "shortestSpan Span method should throw an exception" << '\n';
		return (1);
	}
	catch(const std::exception& e) {}

	try
	{
		sp.longestSpan();
		std::cerr << __FILE__ << ":" << __LINE__ << ": " << "longestSpan Span method should throw an exception" << '\n';
		return (1);
	}
	catch(const std::exception& e) {}

	sp.addNumber(6);

	try
	{
		sp.shortestSpan();
		std::cerr << __FILE__ << ":" << __LINE__ << ": " << "shortestSpan Span method should throw an exception" << '\n';
		return (1);
	}
	catch(const std::exception& e) {}

	try
	{
		sp.longestSpan();
		std::cerr << __FILE__ << ":" << __LINE__ << ": " << "longestSpan Span method should throw an exception" << '\n';
		return (1);
	}
	catch(const std::exception& e) {}

	sp.addNumber(3);

	if (sp.shortestSpan() != 3)
	{
		std::cerr << __FILE__ << ":" << __LINE__ << ": " << "shortestSpan() should return 2" << std::endl;
		return (1);
	}
	if (sp.longestSpan() != 3)
	{
		std::cerr << __FILE__ << ":" << __LINE__ << ": " << "longestSpan() should return 3" << std::endl;
		return (1);
	}

	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	if (sp.shortestSpan() != 2)
	{
		std::cerr << __FILE__ << ":" << __LINE__ << ": " << "shortestSpan() should return 2" << std::endl;
		return (1);
	}
	if (sp.longestSpan() != 14)
	{
		std::cerr << __FILE__ << ":" << __LINE__ << ": " << "longestSpan() should return 14" << std::endl;
		return (1);
	}

	try
	{
		sp.addNumber(42);
		std::cerr << __FILE__ << ":" << __LINE__ << ": " << "addNumber Span method should throw an exception" << '\n';
		return (1);
	}
	catch(const std::exception& e) {}
	return (0);
}

int	short_range_tests()
{
	Span sp = Span(10);
	std::vector<int> v(11, 42);

	try
	{
		sp.addNumbers<std::vector<int> >(v.begin(), v.end());
		std::cerr << __FILE__ << ":" << __LINE__ << ": " << "addNumbers Span method should throw an exception" << '\n';
		return (1);
	}
	catch(const std::exception& e) {}

	v = std::vector<int>(10, 42);
	sp.addNumbers<std::vector<int> >(v.begin(), v.end());

	return (0);
}

int	long_range_tests()
{
	Span sp = Span(10000);
	std::vector<int> v(10001, 42);

	try
	{
		sp.addNumbers<std::vector<int> >(v.begin(), v.end());
		std::cerr << __FILE__ << ":" << __LINE__ << ": " << "addNumbers Span method should throw an exception" << '\n';
		return (1);
	}
	catch(const std::exception& e) {}

	v = std::vector<int>(9999, 42);
	sp.addNumbers<std::vector<int> >(v.begin(), v.end());

	sp.addNumber(42);

	if (sp.longestSpan() != 0)
	{
		std::cerr << __FILE__ << ":" << __LINE__ << ": " << "longestSpan() should return 0" << std::endl;
		return (1);
	}

	try
	{
		sp.addNumber(42);
		std::cerr << __FILE__ << ":" << __LINE__ << ": " << "addNumber Span method should throw an exception" << '\n';
	}
	catch(const std::exception& e) {}

	return (0);
}

int	very_long_range_tests()
{
	Span sp = Span(1000000);
	std::vector<int> v(999, 42);
	sp.addNumbers<std::vector<int> >(v.begin(), v.end());

	sp.addNumber(-42);

	if (sp.longestSpan() != 84)
	{
		std::cerr << __FILE__ << ":" << __LINE__ << ": " << "longestSpan() should return 84" << std::endl;
		return (1);
	}

	v = std::vector<int>(9000, 4242);
	sp.addNumbers(v.begin().base(), v.end().base());

	if (sp.longestSpan() != 4284)
	{
		std::cerr << __FILE__ << ":" << __LINE__ << ": " << "longestSpan() should return 4284" << std::endl;
		return (1);
	}
	return (0);
}

int main()
{
	if (construction_tests())
		return (EXIT_FAILURE);
	if (basic_tests())
		return (EXIT_FAILURE);
	if (short_range_tests())
		return (EXIT_FAILURE);
	if (long_range_tests())
		return (EXIT_FAILURE);
	if (very_long_range_tests())
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}