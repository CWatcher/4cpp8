#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>

template < typename TContainer >
void	test()
{
	try
	{	int	nums[] = { 3, 5, 7, 19, 21, 23, 42 };
		TContainer	container (	nums,  nums + sizeof( nums ) / sizeof( nums[0] ) );
		std::cout << *easyfind( container , 21 ) << std::endl;
		std::cout << *easyfind( container , 22 ) << std::endl;
	}
	catch ( const std::exception& e )
	{	std::cout << e.what() << std::endl;
	}
}
int		main()
{
	test< std::vector< int > >();
	test< std::list< int > >();
}
