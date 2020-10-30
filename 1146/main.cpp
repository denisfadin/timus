#include <cstdint>
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
   uint32_t N;
   std::cin >> N;

   std::vector< int32_t > matrix( N * N, 0 );

   for( uint32_t i = 0; i < N; ++i )
      for( uint32_t j = 0; j < N; ++j )
         std::cin >> matrix[ i * N + j ];

   for( uint32_t i = 0; i < N; ++i )
      for( uint32_t j = 0; j < N; ++j )
      {
         int32_t r_u = i > 0 ? matrix[ (i-1) * N + j ] : 0;
         int32_t r_l = j > 0 ? matrix[ i * N + j - 1 ] : 0;
         int32_t r_d = ( i > 0 && j > 0 ) ? matrix[ (i-1) * N + j - 1 ]: 0;

         matrix[ i*N + j ] += ( r_u + r_l - r_d );
      }



   int32_t result = matrix[ 0 ];
   for( uint32_t i1 = 0; i1 < N; ++i1 )
      for( uint32_t i2 = i1; i2 < N; ++i2 )
         for( uint32_t j1 = 0; j1 < N; ++j1 )
            for( uint32_t j2 = j1; j2 < N; ++j2 )
            {
               int32_t sum = matrix[ i2 * N + j2 ];
               if( i1 > 0 )
                  sum -= matrix[ (i1-1) * N + j2 ];
               if( j1 > 0 )
                  sum -= matrix[ i2 * N + j1 - 1 ];
               if( i1 > 0 && j1 > 0 )
                  sum += matrix[ (i1-1) * N + j1 - 1 ];

               result = std::max( result, sum );
            }

   std::cout << result << std::endl;

   return 0;
}
