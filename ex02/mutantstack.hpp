#pragma once
#include <stack>
#include <ostream>

template < typename T, typename TContainer = std::deque< T > >
class MutantStack : public std::stack< T, TContainer > {
public:
	MutantStack()
	{};
	MutantStack( std::stack< T, TContainer > src )
	:	std::stack< T, TContainer > ( src )
	{}
	~MutantStack()
	{}
	MutantStack& operator=( std::stack< T, TContainer > src )
	{	return static_cast< std::stack< T, TContainer > >( *this ) = src;
	}

	typedef typename std::stack< T, TContainer >::container_type::iterator	iterator;

	iterator begin()
	{	return this->c.begin();
	}
	iterator end()
	{	return this->c.end();
	}
};

template < typename T, typename TContainer >
std::ostream&	operator<<( std::ostream& os, MutantStack< T, TContainer > mstack )
{
	typename MutantStack< T, TContainer >::iterator it = mstack.begin();
	typename MutantStack< T, TContainer >::iterator end = mstack.end();
	os << "{ ";
	while (it != end) {
		os << *it << " ";
		++it;
	}
	return os << " }" << std::endl;
}
