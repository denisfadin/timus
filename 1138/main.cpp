#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <vector>
#include <algorithm>

int main()
{
   uint16_t N, S;
   std::scanf( "%" SCNu16 "%" SCNu16, &N, &S );

   std::vector< uint16_t > data( N + 1, 0 );
   data[ S ] = 1;
   uint16_t result = 1;
   for( uint16_t i = S + 1; i <= N; ++i )
   {
      for( uint16_t j = S; j < i; ++j )
         if( data[ j ] && ( ( i - j ) * 100 ) % j == 0 )
            data[ i ] = std::max( data[ i ], static_cast< uint16_t >( data[ j ] + 1 ) );
      result = std::max( result, data[ i ] );
   }
   std::printf( "%" PRIu16 "\n", result );
}
