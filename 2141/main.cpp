#include <cstdint>
#include <cstdio>
#include <cinttypes>

int main()
{
   uint32_t N;
   std::scanf( "%" SCNu32, &N );

   int64_t positive;
   std::scanf( "%" SCNd64, &positive );
   int64_t negative = 0;
   int64_t result = positive > negative ? positive : negative;
   for( uint32_t i = 1; i < N; ++i )
   {
      int64_t p;
      std::scanf( "%" SCNd64, &p );
      int64_t n = positive - p;
      if( negative > 0 )
         p += negative;

      if( result < p )
         result = p;
      if( result < n )
         result = n;

      positive = p;
      negative = n;
   }

   std::printf( "%" PRId64 "\n", result );

   return 0;
}
