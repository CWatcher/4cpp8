#include "span.hpp"
#include <algorithm>
#include <iostream>
#include <limits>

struct Inc50 {
	int	i;
	Inc50( int start = 0 )
	:	i( start )
	{}
	int operator()()
	{	return i += 50;
	}
};

int	main()
{
	Span sp = Span(5);
	std::cout << "Subject case:"<< std::endl;
	try
	{	sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp;
		sp.printSummary();
		sp.addNumber(42);
	}
	catch( std::exception& e )
	{	std::cout << e.what() << std::endl << std::endl;
	}
	Span sp2( sp );
	std::cout << "INT_MAX test:"<< std::endl;
	try
	{	sp2.size( 10000 );
		sp2.addNumber( std::numeric_limits< int >::max() );
		sp2.addNumber( -3 );
		std::cout << sp2;
		sp2.printSummary();
	}
	catch( const std::exception& e )
	{	std::cout << e.what() << std::endl;
	}
	const int	N = 100000;
	std::cout << "Add " << N << " numbers test:"<< std::endl;
	static int	sequence[ N ];
	Inc50		inc50( -N / 3 * 50 );
	std::generate_n( sequence, N, inc50 );
	Span sp3( N + 1 );
	sp3.addNumbers( sequence, sequence + N );
	sp3.printSummary();
	int	n = 29;
	std::cout << "After " << n << " was added:" << std::endl;
	sp3.addNumber( n );
	sp3.printSummary();
}
