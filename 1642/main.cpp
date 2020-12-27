#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <limits>
#include <algorithm>

int main()
{
   uint16_t N;
   std::scanf( "%" SCNu16, &N );

   int16_t X;
   std::scanf( "%" SCNd16, &X );

   int16_t r = std::numeric_limits< int16_t >::max();
   int16_t l = std::numeric_limits< int16_t >::min();
   for( uint16_t i = 0; i < N; ++i )
   {
      int16_t p;
      std::scanf( "%" SCNd16, &p );

      if( p > 0 )
         r = std::min( r, p );
      else
         l = std::max( l, p );
   }

   if( X > r || X < l )
      std::printf( "Impossible\n" );
   else
   {
      uint16_t r_result = 0, l_result = 0;

      if( X > 0 )
      {
         r_result = X;
         l_result = ( -l << 1 ) + X;
      }
      else
      {
         r_result = ( r << 1 ) + -X;
         l_result = -X;
      }

      std::printf( "%" PRIu16 " %" PRIu16 "\n", r_result, l_result );
   }

   return 0;
}
