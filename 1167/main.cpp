#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <vector>
#include <algorithm>
#include <limits>

int main()
{
   uint_fast16_t N, K;
   std::scanf( "%" SCNuFAST16 "%" SCNuFAST16, &N, &K );

   std::vector< bool > horses( N );
   for( uint_fast16_t i = 0; i < N; ++i )
   {
      uint_fast16_t h;
      std::scanf( "%" SCNuFAST16, &h );
      horses[ i ] = static_cast< bool >( h );
   }

   std::vector< uint16_t > result( K * N, std::numeric_limits< uint16_t >::max() );

   {
      auto const until = N - ( K - 1 );
      uint_fast16_t b = 0, w = 0;
      for( uint_fast16_t i = 0; i < until; ++i )
      {
         if( horses[ i ] )
            ++b;
         else
            ++w;
         result[ i ] = b * w;
      }

      for( uint_fast16_t k = 1; k < K; ++k )
      {
         auto const until = N - ( K - k - 1 );
         for( uint_fast16_t i = k; i < until; ++i )
         {
            auto const prev_unhappiness = result[ ( k - 1 ) * N + ( i - 1 ) ];
            uint_fast16_t b = 0, w = 0;
            for( uint_fast16_t j = i; j < until; ++j )
            {
               if( horses[ j ] )
                   ++b;
                else
                   ++w;

               auto const unhappiness = static_cast< decltype( prev_unhappiness ) >( prev_unhappiness + b * w );

               auto const key = k * N + j;
               result[ key ] = std::min( result[ key ], unhappiness );
            }
         }
      }
   }

   std::printf( "%" PRIu32 "\n", result[ K * N - 1 ] );

}
