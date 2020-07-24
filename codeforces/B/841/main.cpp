#include <iostream>
#include <stdint.h>

int main()
{
   int32_t n;
   std::cin >> n;

   bool res = false;

   for( int i = 0; i < n; ++i )
   {
      int32_t a;
      //std::cin >> a;
      scanf( "%ld", &a );

      if( a&1 )
      {
         res = true;
         break;
      }
   }

   std::cout << ( res ? "First" : "Second" ) << std::endl;

   return 0;
}
