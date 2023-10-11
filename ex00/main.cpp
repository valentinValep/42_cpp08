#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>

int main( void )
{
	std::vector<int> v;
	std::list<int> l;
	std::deque<int> d;

	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
		l.push_back(i);
		d.push_back(i);
	}

	std::vector<int>::iterator it = easyfind(v, 5);
	std::list<int>::iterator it2 = easyfind(l, 1);
	std::deque<int>::iterator it3 = easyfind(d, 9);

	std::cout << *it << std::endl;
	std::cout << *it2 << std::endl;
	std::cout << *it3 << std::endl;

	try
	{
		std::vector<int>::iterator it4 = easyfind(v, 42);
		std::cout << *it4 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}