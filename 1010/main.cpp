#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <cstdlib>

int main()
{
   uint32_t N;
   std::scanf( "%" SCNu32, &N );

   int64_t y1, y2;
   std::scanf( "%" SCNd64 "%" SCNd64, &y1, &y2 );

   int64_t max = std::abs( y2 - y1 );
   uint32_t x1 = 1;
   for( uint32_t i = 2; i < N; ++i )
   {
      y1 = y2;
      std::scanf( "%" SCNd64, &y2 );

      int64_t m = std::abs( y2 - y1 );
      if( max < m )
      {
         x1 = i;
         max = m;
      }
   }

   std::printf( "%" PRIu32 " %" PRIu32 "\n", x1, x1 + 1 );

   return 0;
}
