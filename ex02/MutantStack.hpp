#pragma once

#include <iostream>
#include <stack>

template <typename T>
class MutantStack: public std::stack<T>
{
private:
	/* data */
public:
	MutantStack();
	MutantStack(const MutantStack &src);
	~MutantStack();
	MutantStack	&operator=(const MutantStack &src);

	typedef typename std::stack<T>::container_type::iterator iterator;
	iterator	begin();
	iterator	end();
};

#include "MutantStack.tpp"
