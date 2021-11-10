#include <cstdint>
#include <cstdio>
#include <cinttypes>

int main()
{
   uint32_t N;
   std:scanf( "%" SCNu32, &N );

   uint32_t curr_min;
   std::scanf( "%" SCNu32, &curr_min );

   uint32_t max_pos = 1;
   uint32_t max_compare = 0;

   uint32_t curr_pos = 1;
   uint32_t curr_compare = 0;

   for( uint32_t i = 2; i <= N; ++i )
   {
      ++curr_compare;
      if( max_compare < curr_compare )
      {
         max_compare = curr_compare;
         max_pos = curr_pos;
      }

      uint32_t a;
      std::scanf( "%" SCNu32, &a );

      if( a < curr_min )
      {
         curr_min = a;
         curr_pos = i;
         curr_compare = 1;
      }
   }

   std::printf( "%" PRIu32 "\n", max_pos );

   return 0;
}
