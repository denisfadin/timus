#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <unordered_map>
#include <vector>
#include <algorithm>

int main()
{
   uint_fast16_t N, K;
   std::scanf( "%" SCNuFAST16 "%" SCNuFAST16, &N, &K );

   std::vector< bool > horses( N + 1 );
   for( uint_fast16_t i = 1; i <= N; ++i )
   {
      uint_fast16_t h;
      std::scanf( "%" SCNuFAST16, &h );
      horses[ i ] = static_cast< bool >( h );
   }

   std::unordered_map< uint32_t, uint16_t > result;

   {
      auto const until = N - ( K - 1 );
      uint_fast16_t b = 0, w = 0;
      for( uint_fast16_t i = 1; i <= until; ++i )
      {
         if( horses[ i ] )
            ++b;
         else
            ++w;
         result[ ( 1 << 16 ) + i ] = b * w;
      }

      for( uint_fast16_t k = 2; k <= K; ++k )
      {
         auto const until = N - ( K - k );
         for( uint_fast16_t i = k; i <= until; ++i )
         {
            auto const prev_unhappiness = result[ ( ( k - 1 ) << 16 ) + ( i - 1 ) ];
            uint_fast16_t b = 0, w = 0;
            for( uint_fast16_t j = i; j <= until; ++j )
            {
               if( horses[ j ] )
                   ++b;
                else
                   ++w;

               auto const unhappiness = static_cast< decltype( prev_unhappiness ) >( prev_unhappiness + b * w );
               auto const key = ( k << 16 ) + j;
               auto it = result.find( key );
               if( it == result.end() )
                  result[ key ] = unhappiness;
               else
                  it->second = std::min( it->second, unhappiness );
            }
         }
      }
   }

   std::printf( "%" PRIu32 "\n", result[ ( K << 16 ) + N ] );

}
