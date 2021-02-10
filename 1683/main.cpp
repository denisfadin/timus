#include <cstdint>
#include <cstdio>
#include <cinttypes>

int main()
{
   uint32_t N;
   std::scanf( "%" SCNu32, &N );

   if( N == 1 )
   {
      std::printf( "0\n" );
      return 0;
   }

   uint32_t result = 0;
   uint32_t n = N;
   while( n != 1 )
   {
      ++result;
      n -= n >> 1;
   }

   std::printf( "%" PRIu32 "\n", result );

   n = N;
   while( n != 1 )
   {
      std::printf( "%" PRIu32 " ", n >> 1 );
      n -= n >> 1;
   }

   std::printf( "\n" );

   return 0;
}
