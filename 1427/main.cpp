#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <vector>
#include <algorithm>
#include <cctype>

int main()
{
   uint16_t N, M;
   std::scanf( "%" SCNu16 "%" SCNu16 " ", &N, &M );

   std::vector< uint16_t > suitable_symbols_data( 100001, 0 );
   uint32_t text_size = 0;
   while( true )
   {
      char sym = std::getchar();
      if( sym == '\n' || sym == EOF )
         break;
      ++text_size;
      if( std::isalpha( sym ) || sym == ' ' )
      {
         uint16_t tmp = suitable_symbols_data[ text_size - 1 ];
         ++tmp;
         suitable_symbols_data[ text_size ] = std::min( tmp, M );
      }
   }

   std::vector< uint32_t > dp( text_size + 1, 1 );
   for( uint32_t i = N + 1; i <= text_size; ++i )
   {
      dp[ i ] = dp[ i - N ] + 1;

      uint32_t TO = suitable_symbols_data[ i ];
      if( TO <= N )
         continue;

      if( TO >= i )
      {
         dp[ i ] = 1;
         continue;
      }

      dp[ i ] = std::min( dp[ i ], dp[ i - TO ] + 1 );
   }

   std::printf( "%" PRIu32 "\n", dp[ text_size ] );

   return 0;
}
