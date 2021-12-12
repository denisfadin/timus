#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <vector>

std::vector< uint32_t > calc_prefix( std::vector< char > const& s )
{
	uint32_t n = static_cast< uint32_t >( s.size() );
	std::vector< uint32_t > pi( n );
    pi[ 0 ] = 0;
	for( uint32_t i = 1; i < n; ++i )
    {
		uint32_t j = pi[ i-1 ];
		while( j > 0 && s[ i ] != s[ j ] )
    	   j = pi[ j-1 ];
		if( s[ i ] == s[ j ] )
            ++j;
		pi[ i ] = j;
	}
	return pi;
}

// kmp algorithm
int32_t find( std::vector< char > const& str, std::vector< char > const& pattern )
{
    std::vector< uint32_t > pattern_prefix = calc_prefix( pattern );

    uint32_t i = 0, j = 0;
    while( i < str.size() && j < pattern.size() )
    {
        if( str[ i ] == pattern[ j ] )
        {
            ++i;
            ++j;
            if( j == pattern.size() )
                return i - pattern.size();
        }
        else
        {
            if( j == 0 )
                ++i;
            else
                j = pattern_prefix[ j - 1 ];
        }
    }
    return -1;
}

int main()
{
    uint32_t N;
    std::scanf( "%" SCNu32 " ", &N );

    std::vector< char > pattern( N );
    for( uint32_t i = 0; i < N; ++ i )
        pattern[ i ] = std::getchar();

    std::getchar();

    std::vector< char > str( 2*N );
    for( uint32_t i = 0; i < N; ++i )
        str[ i ] = str[ i + N ] = std::getchar();

    std::printf( "%" PRId32 "\n", find( str, pattern ) );

    return 0;
}
