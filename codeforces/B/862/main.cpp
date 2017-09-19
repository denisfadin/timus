#include <stdio.h>
#include <stdint.h>
#include <algorithm>

int main()
{
   int32_t n;
   scanf( "%d", &n );

   for( int32_t i = 0; i < n-1; ++i )
   {
      int32_t x, y;
      scanf( "%d%d", &x, &y );
   }

   int32_t a = 0, b = 0;

   int32_t k = n-1;
   int32_t i = 1;
   bool need_a = true;
   while( k > 0 )
   {
      auto min = std::min( i, k );
      if( need_a )
         a += min;
      else
         b += min;

      need_a = !need_a;

      k -= min;
      i *= 2;
   }

   printf( "%d\n", a*b - ( n-1 ) );
}
