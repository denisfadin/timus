#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <vector>
#include <algorithm>
#include <cctype>

int main()
{
   uint32_t N, M;
   std::scanf( "%" SCNu32 "%" SCNu32 " ", &N, &M );

   std::vector< uint32_t > suitable_symbols_data( 100000, 0 );
   uint32_t text_size = 0;
   while( true )
   {
      char sym = std::getchar();
      if( sym == '\n' || sym == EOF )
         break;
      if( std::isalpha( sym ) || sym == ' ' )
      {
         suitable_symbols_data[ text_size ] = 1;
         if( text_size )
            suitable_symbols_data[ text_size ] += suitable_symbols_data[ text_size - 1 ];
      }
      ++text_size;
   }

   if( text_size == 0 )
   {
      std::printf( "1\n" );
      return 0;
   }

   std::vector< uint32_t > dp( text_size, 1 );
   for( uint32_t i = N; i < text_size; ++i )
   {
      dp[ i ] = dp[ i - N ] + 1;

      uint32_t TO = std::min( suitable_symbols_data[ i ], M );
      if( TO <= N )
         continue;

      if( TO > i )
      {
         dp[ i ] = 1;
         continue;
      }

      dp[ i ] = std::min( dp[ i ], dp[ i - TO ] + 1 );
   }

   std::printf( "%" PRIu32 "\n", dp[ text_size - 1 ] );

   return 0;
}
