#include "mutantstack.hpp"
#include <iostream>
#include <list>


template < typename TContainer >
void	printContainer( TContainer container )
{
	std::cout << "{ ";
	typename TContainer::iterator it = container.begin();
	for (; it != container.end(); it++ )
		std::cout << *it << " ";
	std::cout << "}" << std::endl;
}

int main()
{
	MutantStack<int> mstack;
	// mstack.push(5);
	// mstack.push(17);
	// std::cout << mstack.top() << std::endl;
	// mstack.pop();
	// std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(21);
	mstack.push(42);
	printContainer( mstack );
	mstack.pop();
	std::cout << "Pop(), Top  : " << mstack.top() << std::endl;
	mstack.push( ~(-1U >> 1) );
	std::cout << "Push(), Size : " << mstack.size() << std::endl;
	std::stack<int> s(mstack);
	MutantStack< int > mstack2( s );
	MutantStack< int > mstack3;
	mstack3 = mstack2;
	std::cout << "After copy constructors(), operator=() :\n";
	printContainer( mstack3 );
	return 0;
}
