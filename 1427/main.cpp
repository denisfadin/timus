#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cctype>

int main()
{
   uint32_t N, M;
   std::scanf( "%" SCNu32 "%" SCNu32 " ", &N, &M );

   std::vector< char > text( 100001, 0 );
   for( uint32_t i = 0; ; ++i )
   {
      char sym = std::getchar();
      if( sym == '\n' || sym == EOF )
         break;
      text[ i ] = sym;
   }

   uint32_t text_size = std::strlen( text.data() );
   if( text_size == 0 )
   {
      std::printf( "1\n" );
      return 0;
   }

   std::vector< uint32_t > dp( text_size, 1 );

   auto is_suitable_symbol = [ &text ]( uint32_t i )
   {
      return std::isalpha( text[ i ] ) || text[ i ] == ' ';
   };

   for( uint32_t i = N; i < text_size; ++i )
   {
      dp[ i ] = dp[ i - 1 ] + 1;
      bool only_suitable_symbols = is_suitable_symbol( i );
      for( uint32_t j = 1; j <= N; ++j )
      {
         dp[ i ] = std::min( dp[ i ], dp[ i - j ] + 1 );
         if( only_suitable_symbols && !is_suitable_symbol( i - j ) && j < N )
            only_suitable_symbols = false;
      }

      if( only_suitable_symbols )
      {
         for( uint32_t j = N + 1; j <= M; ++j )
         {
            if( !is_suitable_symbol( ( i + 1 ) - j ) )
               break;

            if( j > i )
            {
               dp[ i ] = 1;
               break;
            }

            dp[ i ] = std::min( dp[ i ], dp[ i - j ] + 1 );
         }
      }
   }

   std::printf( "%" PRIu32 "\n", dp[ text_size - 1 ] );

   return 0;
}
