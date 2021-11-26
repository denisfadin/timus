#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <cmath>

double calc () {
   uint32_t a, b;
   std::scanf( "%" SCNu32 " %" SCNu32, &a, &b );

   if( a == 1 )
      return b * 2;
   else if( a == 2 )
      return b;
   else
      return std::sqrt( 3 ) * b / 2.0;
}

int main()
{
   uint32_t a, b;
   std::scanf( "%" SCNu32 " %" SCNu32, &a, &b );

   double f;
   if( a == 1 )
      f = b * 2;
   else if( a == 2 )
      f = b * std::sqrt( 2 );
   else if( a == 3 )
      f = b;

   uint32_t N;
   std::scanf( "%" SCNu32, &N );

   uint32_t result = 0;
   for( uint32_t i = 0; i < N; ++i )
      if( calc() <= f )
         ++result;

   std::printf( "%" PRIu32 "\n", result );

   return 0;
}
