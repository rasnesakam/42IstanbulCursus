# include <iostream>
# include <algorithm>

template <typename T>
int easyfind(T& container, int needle){
	typename T::iterator iterator = std::find(container.begin(),container.end(),needle);
	if ( iterator == container.end() )
		return ( -1 );
	return ( std::distance( container.begin(), iterator ) );
}