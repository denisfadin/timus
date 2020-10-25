#include <cstdint>
#include <iostream>
#include <vector>
#include <iomanip>

int main()
{
   uint32_t N, K;
   std::cin >> N >> K;

   std::vector< uint32_t > buf( N );
   for( uint32_t i = 0; i < N; ++i )
      std::cin >> buf[ i ];

   uint32_t const lines = ( N % K ? ( N + K - ( N % K ) ) : N ) / K;

   for( uint32_t l = 0; l < lines; ++l )
   {
      for( uint32_t k = 0; k < K; ++k )
      {
         auto pos = k * lines + l;
         if( pos >= buf.size() )
            break;
         std::cout << std::setw( 4 ) << buf[ pos ];
      }
      std::cout << std::endl;
   }

   return 0;
}
