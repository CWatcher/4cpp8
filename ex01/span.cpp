#include "span.hpp"
#include <algorithm>

Span::Span( unsigned n )
:	_n ( n )
{}
Span::Span( const Span& src )
:	_n( src._n ), _nums( src._nums )
{}
Span::~Span()
{}

Span& Span::operator=( const Span& src )
{
	_n = src._n;
	_nums = src._nums;
	return *this;
}

void Span::addNumber( int num )
{
	if ( _nums.size() >= _n )
		throw ( std::overflow_error("Span is full") );

	_nums.push_back( num );
}
unsigned long long Span::shortestSpan()
{
	return 0;
}
unsigned long long Span::longestSpan()
{
	return 1;
}
