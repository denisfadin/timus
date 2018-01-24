#include <iostream>
#include <cstdint>
#include <cmath>

uint32_t f( uint16_t n, uint16_t k )
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
   uint16_t n, k;
   std::cin >> n >> k;

   std::cout << f(n,k) << std::endl;

   return 0;
}
