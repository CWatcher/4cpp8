#pragma once
#include <algorithm>
#include <stdexcept>

template< typename TContainer >
typename TContainer::iterator	easyfind( TContainer& haystack, int needle )
{
	typename TContainer::iterator it = find( haystack.begin(), haystack.end(), needle );
	if ( it == haystack.end() )
		throw ( std::logic_error("Not found") );
	return it;
}
