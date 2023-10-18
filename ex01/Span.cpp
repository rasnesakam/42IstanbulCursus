#include "Span.hpp"

Span::Span() : n( 0 ){}

Span::Span( unsigned int n ) : n( n ){}

Span::Span( Span const & src )
{
	*this = src;
	return ;
}

Span::~Span(){}

Span & Span::operator=( Span const & rhs )
{
	if ( this != &rhs )
	{
		this->n = rhs.n;
		this->spanList = rhs.spanList;
	}
	return ( *this );
}

void	Span::addNumber( int const & number )
{
	if ( this->spanList.size() < this->n )
		this->spanList.push_back( number );
	else
		throw std::runtime_error( "Out of vector limits" );
}

void	Span::fill( int const & number )
{
	srand( time( NULL ) );

	int	avaiableSlots = ( this->n - (int)this->spanList.size() );

	if ( number > avaiableSlots )
		throw std::runtime_error( "Out of vector limits" );

	for ( int i = 0; i < number; i++ )
	{
		int randNumber = rand();

		std::vector<int>::iterator it = find(this->spanList.begin(), this->spanList.end(), randNumber);
		if ( it == this->spanList.end() )
			this->addNumber( randNumber );
	}
}

int	Span::shortestSpan() const
{
	if ( this->spanList.size() < 2 )
		throw std::runtime_error( "The container has only one number" );

	int	minSpan = std::numeric_limits<int>::max();
	std::vector<int> aux = this->spanList;

	sort( aux.begin(), aux.end() );
	for ( int i = 0; i < int(aux.size()) - 1; i++)
	{
		if ( abs( aux[i] - aux[i + 1]) < minSpan )
			minSpan = abs( aux[i] - aux[i + 1] );
	}
	return ( minSpan );
}

int	Span::longestSpan() const
{
	if ( this->spanList.size() < 2 )
		throw std::runtime_error( "The container has only one number" );

	int	max = *max_element(this->spanList.begin(), this->spanList.end());
	int	min = *min_element(this->spanList.begin(), this->spanList.end());
	return ( max - min );
}

std::vector<int>	Span::getVector( void ) const
{
	return ( this->spanList );
}
unsigned int		Span::getN( void ) const
{
	return ( this->n );
}

std::ostream& operator << ( std::ostream& o, const Span& span )
{
	std::vector<int>	temp_vec = span.getVector();
	unsigned int		temp_n = span.getN();

	std::cout << "Total size: " << temp_n << std::endl;
	std::cout << "Filled size: " << temp_vec.size() << std::endl;
	for ( int i = 0; i < (int)temp_vec.size(); i++ )
	{
		std::cout << "index " << i << ": " << temp_vec[i] << std::endl;
	}
	return ( o );
}