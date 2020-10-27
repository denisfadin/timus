#include <cstdint>
#include <iostream>
#include <string>
#include <string_view>

int main()
{
   uint32_t N;
   std::cin >> N;

   std::string buf( ( N << 1 ) + 1, 0 );
   for( uint32_t i = 0; i < N; ++i )
      std::cin >> &buf[ i << 1 ];

   char L;
   std::cin >> L;
   for( uint32_t i = 0; i < N; ++i )
   {
      if( L == buf[ i << 1 ] )
         std::cout << std::string_view{ &buf[ i << 1 ], 2 } << std::endl;
   }
   return 0;
}
