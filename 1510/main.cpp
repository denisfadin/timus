#include <cstdint>
#include <cstdio>
#include <cinttypes>

int main()
{
   uint32_t N;
   std::scanf( "%" SCNu32, &N );

   uint32_t result;
   uint32_t result_count = 0;

   uint32_t k;
   for( uint32_t i = 0; i < N; ++i )
   {
      std::scanf( "%" SCNu32, &k );
      if( result_count == 0 || result == k )
      {
         result = k;
         ++result_count;
      }
      else
         --result_count;
   }

   std::printf( "%" PRIu32 "\n", result );

   return 0;
}
