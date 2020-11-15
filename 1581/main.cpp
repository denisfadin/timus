#include <cstdint>
#include <cstdio>
#include <cinttypes>

int main()
{
   uint32_t N;
   std::scanf( "%" SCNu32, &N );

   uint32_t num;
   std::scanf( "%" SCNu32, &num );
   uint32_t count = 1;

   for( uint32_t i = 1; i < N; ++i )
   {
      uint32_t n;
      std::scanf( "%" SCNu32, &n );
      if( num == n )
         ++count;
      else
      {
         std::printf( "%" PRIu32 " %" PRIu32 " ", count, num );
         count = 1;
         num = n;
      }
   }

   std::printf( "%" PRIu32 " %" PRIu32 "\n", count, num );

   return 0;
}
