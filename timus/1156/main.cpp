#include <cstdint>
#include <vector>
#include <deque>
#include <iostream>

int main()
{
   uint32_t n, m;
   std::cin >> n >> m;

   std::vector< bool > similar_tasks_arr( 2*n, false );
   std::vector< bool > similar_tasks_links( 2*n * 2*n, false );

   for( uint32_t i = 0; i < m; ++i )
   {
      uint32_t x, y;
      std::cin >> x >> y;
      --x;
      --y;

      similar_tasks_arr[ x ] = true;
      similar_tasks_arr[ y ] = true;

      similar_tasks_links[ x*2*n+y ] = similar_tasks_links[ y*2*n+x ] = true;
   }

   std::vector< bool > marked( 2*n, false );
   std::vector< int8_t > marks( 2*n, 0 );
   for( uint32_t i = 0; i < 2*n; ++i )
   {
      if( !similar_tasks_arr[ i ] )
         continue;

      std::deque< uint32_t > list;
      list.push_back( i );

      while( !list.empty() )
      {
         uint32_t e = list.front();
         list.pop_front();

         if( marked[ e ] )
            continue;

         marked[ e ] = true;
         if( !marks[ e ] )
         {
            marks[ e ] = -1;
            //std::cout << e << " -> 1" << std::endl;
         }

         for( uint32_t j = 0; j < 2*n; ++j )
         {
            if( similar_tasks_links[ e*2*n+j ] )
            {
               if( !marks[ j ] )
               {
                  marks[ j ] = -marks[ e ];
                  //std::cout << j << " --> " << (int32_t)marks[ j ] << std::endl;
               }
               else if( marks[ j ] != -marks[ e ] )
               {
                  //std::cout << j << " != " << e << std::endl;
                  std::cout << "IMPOSSIBLE" << std::endl;
                  return 0;
               }

               list.push_back( j );
            }
         }
      }
   }

   uint32_t l = 0, r = 0;
   for( uint32_t i = 0; i < 2*n; ++i )
   {
      if( marks[ i ] == -1 )
         ++l;
      else if( marks[ i ] == 1 )
         ++r;
   }

   if( l > n || r > n )
   {
      std::cout << "IMPOSSIBLE" << std::endl;
      return 0;
   }

   for( uint32_t i = 0; i < 2*n; ++i )
   {
      if( l == n )
         break;
      if( !marks[ i ] )
      {
         marks[ i ] = -1;
         ++l;
      }
   }

   for( uint32_t i = 0; i < 2*n; ++i )
   {
      if( marks[ i ] == -1 )
         std::cout << i+1 << " ";
   }

   std::cout << std::endl;

   for( uint32_t i = 0; i < 2*n; ++i )
   {
      if( marks[ i ] != -1 )
         std::cout << i+1 << " ";
   }

   std::cout << std::endl;

   return 0;
}
