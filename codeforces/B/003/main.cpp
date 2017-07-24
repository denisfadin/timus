#include <iostream>
#include <stdint.h>
#include <vector>
#include <algorithm>
#include <memory>

struct Boat
{
   int32_t idx;
   int16_t capacity;
};

int main()
{
   int32_t N, V;
   std::cin >> N >> V;

   std::vector< Boat > kayaks;
   std::vector< Boat > catamarans;
   for( int32_t i = 0; i < N; ++i )
   {
      int16_t type;

      Boat b;
      b.idx = i+1;
      std::cin >> type >> b.capacity;

      if( type == 1 )
         kayaks.emplace_back( std::move( b ) );
      else
         catamarans.emplace_back( std::move( b ) );
   }

   std::sort( kayaks.begin(), kayaks.end(), []( Boat const& a, Boat const& b ) -> bool {
      return a.capacity < b.capacity;
   });

   std::sort( catamarans.begin(), catamarans.end(), []( Boat const& a, Boat const& b ) -> bool {
      return a.capacity < b.capacity;
   });

   std::unique_ptr< Boat > last_kayak;

   int32_t result_capacity = 0;
   std::vector< int32_t > result_idxs;
   int32_t result_V = 0;

   while( result_V < V )
   {
      if( kayaks.empty() && catamarans.empty() )
         break;

      // может поместиться только байдарка,
      // но нужно проверить и случай, если убрать последнюю добавленную байдарку и добавить катамаран
      if( V - result_V == 1 )
      {
         int32_t k = 0;
         if( kayaks.size() > 0 )
            k = kayaks[ kayaks.size()-1 ].capacity;

         int32_t c = 0;
         if( catamarans.size() > 0 )
            c = catamarans[ catamarans.size()-1 ].capacity;

         if( last_kayak && c - last_kayak->capacity > k )
         {
            result_idxs.push_back( catamarans.back().idx );
            result_capacity += catamarans.back().capacity;
            result_idxs.erase( std::find( result_idxs.begin(), result_idxs.end(), last_kayak->idx ) );
            result_capacity -= last_kayak->capacity;
            result_V += (2-1);
         }
         else if( k > 0 )
         {
            result_idxs.push_back( kayaks.back().idx );
            result_capacity += kayaks.back().capacity;
            kayaks.pop_back();
            result_V += 1;
         }

         break;
      }

      int32_t k = 0;
      int8_t k_V = 0;
      if( kayaks.size() > 0 )
      {
         k = kayaks[ kayaks.size()-1 ].capacity;
         k_V = 1;
         if( kayaks.size() > 1 )
         {
            k += kayaks[ kayaks.size()-2 ].capacity;
            k_V = 2;
         }
      }

      int32_t c = 0;
      if( catamarans.size() > 0 )
         c = catamarans[ catamarans.size()-1 ].capacity;

      if( k > c )
      {
         result_idxs.push_back( kayaks.back().idx );
         result_capacity += kayaks.back().capacity;
         last_kayak.reset( new Boat( kayaks.back() ) );
         kayaks.pop_back();
         if( k_V > 1 )
         {
            result_idxs.push_back( kayaks.back().idx );
            result_capacity += kayaks.back().capacity;
            last_kayak.reset( new Boat( kayaks.back() ) );
            kayaks.pop_back();
         }
         result_V += k_V;
      }
      else
      {
         result_idxs.push_back( catamarans.back().idx );
         result_capacity += catamarans.back().capacity;
         catamarans.pop_back();
         result_V += 2;
      }
   }

   //std::sort( result_idxs.begin(), result_idxs.end() );
   std::cout << result_capacity << std::endl;
   for( int32_t i : result_idxs )
      std::cout << i << " ";

   return 0;
}
