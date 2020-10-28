#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <algorithm>

int main()
{
   uint32_t N;
   scanf( "%" SCNu32, &N );

   int32_t sum = 0, max = 0;
   for( uint32_t i = 0; i < N; ++i )
   {
      int32_t p;
      scanf( "%" SCNd32, &p );

      sum += p;
      if( sum < 0 )
         sum = 0;

      max = std::max( max, sum );
   }

   printf( "%" PRId32 "\n", max );

   return 0;
}
