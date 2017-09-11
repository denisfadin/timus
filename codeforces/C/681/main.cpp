#include <iostream>
#include <stdint.h>
#include <vector>
#include <string>
#include <algorithm>

int main()
{
   int32_t n;
   std::cin >> n;

   std::vector< int32_t > heap;
   std::vector< std::pair< std::string, int32_t > > result;

   auto comp = []( int32_t const& a, int32_t const& b ) -> bool
   {
      return a > b;
   };

   std::string operation;
   for( int32_t i = 0; i < n; ++i )
   {

      std::cin >> operation;

      if( operation == "insert" )
      {
         int32_t x;
         std::cin >> x;
         heap.push_back( x );
         std::push_heap( std::begin( heap ), std::end( heap ), comp );
         result.push_back( std::make_pair( "insert", x ) );
      }
      else if( operation == "getMin" )
      {
         int32_t x;
         std::cin >> x;

         bool need_insert = true;
         while( !heap.empty() )
         {
            if( heap[0] == x )
            {
               need_insert = false;
               break;
            }

            if( heap[0] > x )
               break;

            std::pop_heap( std::begin( heap ), std::end( heap ), comp );
            heap.pop_back();

            result.push_back( std::make_pair( "removeMin", 0 ) );
         }

         if( need_insert )
         {
            heap.push_back( x );
            std::push_heap( std::begin( heap ), std::end( heap ), comp );
            result.push_back( std::make_pair( "insert", x ) );
         }
         result.push_back( std::make_pair( "getMin", x ) );
      }
      else if( operation == "removeMin" )
      {
         if( heap.empty() )
         {
            heap.push_back( 0 );
            result.push_back( std::make_pair( "insert", 0 ) );
         }
         std::pop_heap( std::begin( heap ), std::end( heap ), comp );
         heap.pop_back();
         result.push_back( std::make_pair( "removeMin", 0 ) );
      }
   }

   std::cout << result.size() << std::endl;
   for( auto const& p : result )
   {
      std::cout << p.first;
      if( p.first != "removeMin" )
         std::cout << " " << p.second;
      std::cout << std::endl;
   }

   return 0;
}
