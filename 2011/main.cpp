#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <vector>
#include <algorithm>

int main()
{
   uint16_t N;
   std::scanf( "%" SCNu16, &N );

   std::vector< uint16_t > buf( N, 0 );
   for( uint16_t i = 0; i < N; ++i )
      std::scanf( "%" SCNu16, &buf[ i ] );

   std::sort( buf.begin(), buf.end() );

   uint16_t count = 1;
   while( count < 6 && std::next_permutation( buf.begin(), buf.end() ) )
      ++count;

   std::printf( count == 6 ? "Yes\n" : "No\n" );

   return 0;
}
