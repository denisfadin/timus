#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <vector>
#include <algorithm>

int main()
{
   uint16_t N;
   std::scanf( "%" SCNu16, &N );

   std::vector< uint16_t > data( N, 0 );
   for( uint16_t i = 0; i < N; ++i )
      std::scanf( "%" SCNu16, &data[ i ] );

   std::sort( data.begin(), data.end() );

   uint16_t result = 0;
   uint16_t curr_d = 0;
   uint16_t curr_d_count = 0;
   for( uint16_t d : data )
   {
      if( d == curr_d )
         ++curr_d_count;
      else
      {
         curr_d = d;
         curr_d_count = 1;
      }

      if( curr_d_count == 4 )
      {
         ++result;
         curr_d_count = 0;
      }
   }

   std::printf( "%" PRIu16 "\n", result );

   return 0;
}
