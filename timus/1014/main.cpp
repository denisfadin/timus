#include <cstdint>
#include <iostream>

int64_t getQforN( int32_t n )
{
   if( n == 0 )
      return 10;
   else if( n == 1 )
      return 1;
   else
   {
      int64_t result = 0;
      int64_t p = 1;

      for( int16_t d = 9; d > 1; --d )
      {
         while( n % d == 0 )
         {
            n /= d;
            result += d * p;
            p *= 10;
         }
      }

      return n == 1 ? result : -1;
   }
}

int main()
{
   int32_t n;
   std::cin >> n;

   std::cout << getQforN( n ) << std::endl;

   return 0;
}
