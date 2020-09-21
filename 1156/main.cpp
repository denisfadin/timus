#include <cstdint>
#include <vector>
#include <deque>
#include <iostream>

int main()
{
   uint32_t N, M;
   std::cin >> N >> M;

   uint32_t const TASKS_COUNT = N << 1;
   std::vector< bool > similar_tasks( TASKS_COUNT * TASKS_COUNT, false );

   auto IsTasksLinked = [&]( uint32_t i, uint32_t j ) -> bool
   {
      if( i == j )
         return false;
      return similar_tasks.at( i*TASKS_COUNT+j );
   };

   auto IsTaskLinked = [&]( uint32_t i ) -> bool
   {
      return similar_tasks.at( i*TASKS_COUNT+i );
   };
   
   auto MakeTasksLinked = [&]( uint32_t i, uint32_t j )
   {
      similar_tasks.at( i*TASKS_COUNT+j ) = true;
      similar_tasks.at( j*TASKS_COUNT+i ) = true;

      similar_tasks.at( i*TASKS_COUNT+i ) = true;
      similar_tasks.at( j*TASKS_COUNT+j ) = true;
   };

   for( uint32_t i = 0; i < M; ++i )
   {
      uint32_t x, y;
      std::cin >> x >> y;
      --x;
      --y;

      MakeTasksLinked( x, y );
   }

   std::vector< int8_t > marks( TASKS_COUNT, 0 );
   uint32_t l = 0, r = 0;
   
   for( uint32_t i = 0; i < TASKS_COUNT; ++i )
   {
      if( !IsTaskLinked( i ) )
         continue;

      std::vector< int8_t > local_marks( TASKS_COUNT, 0 );

      std::deque< uint32_t > list;
      list.push_back( i );

      while( !list.empty() )
      {
         uint32_t e = list.front();
         list.pop_front();

         static std::vector< bool > marked( TASKS_COUNT, false );
         if( marked[ e ] )
            continue;
         marked[ e ] = true;

         if( !local_marks[ e ] )
         {
            local_marks[ e ] = -1;
            //std::cout << e << " -> -1" << std::endl;
         }

         for( uint32_t j = 0; j < TASKS_COUNT; ++j )
         {
            if( IsTasksLinked( e, j ) )
            {
               if( !local_marks[ j ] )
               {
                  local_marks[ j ] = -local_marks[ e ];
                  //std::cout << j << " --> " << (int32_t)local_marks[ j ] << std::endl;
               }
               else if( local_marks[ j ] != -local_marks[ e ] )
               {
                  //std::cout << j << " != " << e << std::endl;
                  std::cout << "IMPOSSIBLE" << std::endl;
                  return 0;
               }

               list.push_back( j );
            }
         }
      }

      uint32_t local_l = 0, local_r = 0;
      for( uint32_t i = 0; i < TASKS_COUNT; ++i )
      {
         if( local_marks[ i ] == -1 )
            ++local_l;
         else if( local_marks[ i ] == 1 )
            ++local_r;
      }

      int8_t k = 1;
      if( ( l > r && local_l > local_r ) || ( r > l && local_r > local_l ) )
         k = -1;
      
      for( uint32_t i = 0; i < TASKS_COUNT; ++i )
      {
         if( local_marks[ i ] )
            marks[ i ] = k*local_marks[ i ];
      }

      l += k > 0 ? local_l : local_r;
      r += k > 0 ? local_r : local_l;
   }

   if( l > N || r > N )
   {
      std::cout << "IMPOSSIBLE" << std::endl;
      return 0;
   }

   for( uint32_t i = 0; i < TASKS_COUNT; ++i )
   {
      if( l == N )
         break;
      if( !marks[ i ] )
      {
         marks[ i ] = -1;
         ++l;
      }
   }

   for( uint32_t i = 0; i < TASKS_COUNT; ++i )
   {
      if( marks[ i ] == -1 )
         std::cout << i+1 << " ";
   }

   std::cout << std::endl;

   for( uint32_t i = 0; i < TASKS_COUNT; ++i )
   {
      if( marks[ i ] != -1 )
         std::cout << i+1 << " ";
   }

   std::cout << std::endl;

   return 0;
}
