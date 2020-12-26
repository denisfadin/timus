#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <vector>

int main()
{
   uint32_t N, M;
   std::scanf( "%" SCNu32 "%" SCNu32, &N, &M );

   std::vector< char > digits( N );
   for( uint32_t i = 0; i < N; ++i )
      std::scanf( " %c", &digits[ i ] );

   uint32_t pos = ( M % N );
   for( uint32_t i = 0; i < 10; ++i )
   {
      if( pos == digits.size() )
         pos = 0;
      std::printf( "%c", digits[ pos++ ] );
   }

   std::printf( "\n" );

   return 0;
}
