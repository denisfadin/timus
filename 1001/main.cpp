#include <stdio.h>
#include <math.h>

unsigned long long I[128*1024];

int main()
{
   unsigned long long* p = I;
   for( ; scanf( "%llu", p ) != EOF; ++p )
      ;
   
   for( --p; p >= I; --p )
      printf( "%.4f\n", sqrt( *p ) );
      
   return 0;
}