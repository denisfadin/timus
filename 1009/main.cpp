#include <cstdint>
#include <cstdio>
#include <cinttypes>

uint32_t f( uint32_t n, uint32_t k )
{
  if( n == 0 )
    return 0;
  else if( n == 1 )
    return k-1;
  else if( n == 2 )
    return (k-1)*k;
  else
    return (k-1)*( f(n-1,k)+f(n-2,k) );
}

int main()
{
   uint32_t n, k;
   std::scanf( "%" SCNu32 "%" SCNu32, &n, &k );

   std::printf( "%" PRIu32 "\n", f(n,k) );

   return 0;
}
