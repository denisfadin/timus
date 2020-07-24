#include <cstdio>
#include <cinttypes>

int16_t nod( int16_t a, int16_t b )
{
   while( a != 0 && b != 0 )
   {
      if( a > b )
         a = a % b;
      else
         b = b % a;
   }

   return a + b;
}

int main()
{
   int16_t n;
   scanf( "%" SCNd16, &n );

   int16_t a = ( n / 2 ) - ( (n % 2)==0 ? 1 : 0 ) , b = n - a;
   while( a > 0 )
   {
      if( nod( a, b ) == 1 )
         break;

      a--;
      b++;
   }

   printf( "%" PRId16 " %" PRId16 "\n", a, b );

   return 0;
}
