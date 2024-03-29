#pragma once
#include <set>
#include <stdexcept>
#include <ostream>
#include <iostream>

class Span {
public:
	Span();
	Span( unsigned size );
	Span( const Span& src );
	Span& operator=( const Span& src );
	virtual ~Span();
	void addNumber( int number );
	template <class TIterator>
	void addNumbers( TIterator begin, TIterator end )
	{
		if ( std::distance( begin, end ) + _nums.size() > _size  )
			throw std::overflow_error( "addNumbers(): there is no enough space in the span" );
		_nums.insert( begin, end );
	}
	unsigned	shortestSpan();
	unsigned	longestSpan();
	unsigned	size() const;
	unsigned	size( unsigned );
	void		printSummary();
	void		printNums( std::ostream& os = std::cout );
private:
	unsigned 				_size;
	std::multiset< int >	_nums;
};

std::ostream&	operator<<( std::ostream& os, Span span );
