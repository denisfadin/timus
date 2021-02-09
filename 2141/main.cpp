#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <vector>
#include <algorithm>

int main()
{
   uint32_t N;
   std::scanf( "%" SCNu32, &N );

   std::vector< int64_t > positive( N );
   std::vector< int64_t > negative( N );

   std::scanf( "%" SCNd64, &positive[ 0 ] );
   negative[ 0 ] = 0;
   for( uint32_t i = 1; i < N; ++i )
   {
      std::scanf( "%" SCNd64, &positive[ i ] );
      negative[ i ] = positive[ i - 1 ] - positive[ i ];
      if( negative[ i - 1 ] > 0 )
         positive[ i ] += negative[ i - 1 ];
   }

   int64_t result = std::max( positive[ 0 ], negative[ 0 ] );
   for( uint32_t i = 1; i < N; ++i )
   {
      if( result < positive[ i ] )
         result = positive[ i ];

      if( result < negative[ i ] )
         result = negative[ i ];
   }

   std::printf( "%" PRId64 "\n", result );

   return 0;
}
