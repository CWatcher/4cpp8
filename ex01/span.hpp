#pragma once
#include <set>
#include <stdexcept>

class Span {
public:
	Span();
	Span( unsigned n );
	Span( const Span& src );
	Span& operator=( const Span& src );
	virtual ~Span();
	void addNumber( int number );
	template <class TIterator>
	void addNumbers( TIterator begin, TIterator end )
	{
		if ( std::distance( begin, end ) + _nums.size() > _n  )
			throw std::overflow_error( "addNumbers(): there is no enough space in span" );
		_nums.insert( begin, end );
	}
	unsigned long long shortestSpan();
	unsigned long long longestSpan();
private:
	unsigned 				_n;
	std::multiset< int >	_nums;
};
