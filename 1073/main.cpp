//
// Like the Change-making problem
//
#include <cstdint>
#include <cinttypes>
#include <cstdio>
#include <vector>
#include <algorithm>

int main()
{
   uint32_t N;
   std::scanf( "%" SCNu32, &N );

   std::vector< uint32_t > result( N+1, 0 );
   for( uint32_t i = 1; i <= N; ++i )
      result[ i ] = i;

   std::vector< uint32_t > coins;
   for( uint32_t i = 2; ; ++i )
   {
      auto s = i * i;
      if( s > N )
         break;
      coins.push_back( s );
   }

   for( auto const& c : coins )
      for( uint32_t i = 1; i <= N; ++i )
      {
         if( i == c )
            result[ i ] = 1;
         else if( c < i )
            result[ i ] = std::min( result[ i ], 1 + result[ i - c ] );
      }

   std::printf( "%" PRIu32 "\n", result[ N ] );

   return 0;
}
