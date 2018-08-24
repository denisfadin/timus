#include <iostream>
#include <cstdint>
#include <vector>
#include <algorithm>

int main()
{
   uint32_t n;
   std::cin >> n;

   std::vector< bool > edges( n*n, false );

   for( uint32_t x = 0; x < n; ++x )
   {
      while( true )
      {
         uint32_t y;
         std::cin >> y;
         if( !y )
            break;
         --y;

         edges[x*n+y] = true;
         edges[y*n+x] = true;
      }
   }

   std::vector< int8_t > result( n, -1 );
   result[0] = 0;

   std::vector< uint32_t > queue;
   queue.push_back( 0 );
   for( uint32_t i = 0; i < queue.size(); ++i )
   {
      auto p = queue[i];
      for( uint32_t j = 0; j < n; ++j )
      {
         if( edges[p*n+j] )
         {
            if( result[j] == result[p] )
            {
               std::cout << -1 << std::endl;
               return 0;
            }
            else
            {
               result[j] = !result[p];
               if( std::find( queue.begin(), queue.end(), j ) == queue.end() )
                  queue.push_back( j );
            }
         }
      }
   }

   for( int16_t e : result )
      std::cout << e;
   std::cout << std::endl;

   return 0;
}
