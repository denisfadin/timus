#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <utility>

int main()
{
   int32_t x, y;
   std::scanf( "%" SCNd32 "%" SCNd32, &x, &y );

   if( x > 0 && y > 0 && ( x + y ) % 2 )
      std::swap( x, y );

   std::printf( "%" PRId32 " %" PRId32 "\n", x, y );

   return 0;
}
