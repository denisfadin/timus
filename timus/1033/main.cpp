#include <cstdint>
#include <vector>
#include <iostream>

uint16_t bfs( uint16_t i, uint16_t j, uint16_t N, std::vector< bool > const& matrix, std::vector< bool >& buf )
{
   if( buf[i*N+j] )
      return 0;
   buf[i*N+j]=true;

   uint16_t result = 0;

   // up
   if( i == 0 )
   {
      if( j != 0 )
         result += 1;
   }
   else
   {
      if( matrix[(i-1)*N+j] )
         result += bfs( i-1, j, N, matrix, buf );
      else
         result += 1;
   }

   // down
   if( i == N-1 )
   {
      if( j != N-1 )
         result += 1;
   }
   else
   {
      if( matrix[(i+1)*N+j] )
         result += bfs( i+1, j, N, matrix, buf );
      else
         result += 1;
   }

   // left
   if( j == 0 )
   {
      if( i != 0 )
         result += 1;
   }
   else
   {
      if( matrix[i*N+j-1] )
         result += bfs( i, j-1, N, matrix, buf );
      else
         result += 1;
   }

   // right
   if( j == N-1 )
   {
      if( i != N-1 )
         result += 1;
   }
   else
   {
      if( matrix[i*N+j+1] )
         result += bfs( i, j+1, N, matrix, buf );
      else
         result += 1;
   }
   return result;
}

int main()
{
   uint16_t N;
   std::cin >> N;

   std::vector< bool > matrix( N*N, false );
   for( uint16_t i = 0; i < N; ++i )
      for( uint16_t j = 0; j < N; ++j )
      {
         char sym;
         std::cin >> sym;
         if( sym == '.' )
            matrix[i*N+j] = true;
      }

   std::vector< bool > buf( N*N, false );
   uint16_t result_sum = bfs( 0, 0, N, matrix, buf );
   result_sum += bfs( N-1, N-1, N, matrix, buf );

   std::cout << result_sum*9 << std::endl;

   return 0;
}
