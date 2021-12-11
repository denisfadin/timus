#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <vector>

std::vector< uint32_t > prefix_function( std::vector< char > const& s )
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

int main()
{
    uint32_t N;
    std::scanf( "%" SCNu32 " ", &N );

    std::vector< char > str1( N ), str2( N );

    for( uint32_t i = 0; i < N; ++ i )
        str1[ i ] = std::getchar();

    std::getchar();

    for( uint32_t i = 0; i < N; ++i )
        str2[ i ] = std::getchar();
    std::vector< uint32_t > str2_prefix = prefix_function( str2 );

    int32_t result = -1;

    uint32_t pos = 0;
    uint32_t i = 0, j = 0;

    while( true )
    {
        if( str1[ i ] == str2[ j ] )
        {
            ++j;
            if( j == N )
            {
                if( pos == 0 )
                    result = 0;
                else
                    result = N - pos;
                break;
            }
            ++i;
            if( i == N )
                i = 0;
        }
        else
        {
            if( i < pos )
                break;
            if( j == 0 )
            {
                ++i;
                if( i == N )
                    break;
                pos = i;
            }
            else
            {
                j = str2_prefix[ j-1 ];
                pos = i - j;
            }
        }
    }

    std::printf( "%" PRId32 "\n", result );

    return 0;
}
