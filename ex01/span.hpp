#pragma once
#include <vector>
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
		if ( end - begin + _nums.size() > _n  )
			throw std::exception();

		_nums.insert( _nums.end() - 1, begin, end );
	}
	unsigned long long shortestSpan();
	unsigned long long longestSpan();
private:
	unsigned 			_n;
	std::vector< int >	_nums;
};
