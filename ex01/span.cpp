#include "span.hpp"
#include <numeric>
#include <iterator>
#include <iostream>

Span::Span( unsigned n )
:	_size ( n )
{}
Span::Span( const Span& src )
:	_size( src._size ), _nums( src._nums )
{}
Span::~Span()
{}

Span& Span::operator=( const Span& src )
{
	_size = src._size;
	_nums = src._nums;
	return *this;
}

void Span::addNumber( int num )
{
	if ( _nums.size() >= _size )
		throw ( std::overflow_error( "addNumber(): Span is full" ) );
	_nums.insert( num );
}
unsigned Span::shortestSpan()
{
	std::multiset< unsigned >	numDiffs;
	std::adjacent_difference( _nums.begin(), _nums.end(),
		std::inserter( numDiffs, numDiffs.begin() )
	);
	return *numDiffs.begin();
}
unsigned Span::longestSpan()
{
	if ( _nums.size() < 2 )
		throw std::length_error( "longestSpan(): Span elements < 2" );
	return *--_nums.end() - *_nums.begin();
}
unsigned			Span::size() const
{	return _size; }
unsigned			Span::size( unsigned n )
{
	if ( n < _nums.size() )
		_nums.clear();
	return _size = n;
}
void				Span::printSummary()
{
		std::cout << "shortestSpan: " << shortestSpan() << std::endl;
		std::cout << "longestSpan : " << longestSpan() << std::endl
		          << std::endl;
}
void				Span::printNums ( std::ostream& os )
{
	std::multiset< int >::iterator it = _nums.begin();
	for ( ; it != _nums.end(); it++ )
		os << *it << " ";
}

std::ostream&	operator<<( std::ostream& os, Span span )
{
	os << "size = " << span.size() << ", numbers { ";
	span.printNums( os );
	return os << "} " << std::endl;
}
