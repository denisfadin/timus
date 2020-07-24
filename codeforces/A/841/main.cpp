#include <iostream>
#include <stdint.h>
#include <vector>

int main()
{
   int16_t n, k;
   std::cin >> n >> k;

   std::vector< int16_t > v( 'z' - 'a' + 1, 0 );

   for( int16_t i = 0; i < n; ++i )
   {
      char c;
      std::cin >> c;
      v[ c-'a' ] += 1;
   }

   bool result = true;
   for( int16_t i = 0; i < v.size(); ++i )
      if( v[i] > k )
      {
         result = false;
         break;
      }

   std::cout << ( result ? "YES" : "NO" ) << std::endl;

   return 0;
}
