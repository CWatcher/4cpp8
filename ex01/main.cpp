#include "span.hpp"
#include <vector>
#include <iostream>
#include <limits>

int	main()
{
	Span sp = Span(5);
	try
	{	std::cout << "Subject case:"<< std::endl;
		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.printSummary();
		sp.addNumber(42);
	}
	catch( std::exception& e )
	{	std::cout << e.what() << std::endl;
	}
	try
	{	Span sp2( sp );
		sp2.size( 10000 );
		sp2.addNumber( std::numeric_limits< int >::max() );
		sp2.addNumber( -3 );
		sp2.printSummary();
	}
	catch( const std::exception& e )
	{	std::cout << e.what() << std::endl;
	}
}
