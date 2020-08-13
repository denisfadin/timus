#include <iostream>
#include <cinttypes>
#include <unordered_set>
#include <unordered_map>
#include <iomanip>
#include <limits>
#include <cmath>

using PointT = std::pair< uint32_t, uint32_t >;

PointT MakePoint( uint32_t x, uint32_t y )
{
   return std::make_pair( x, y );
}

namespace std
{
   template<>
   struct hash< PointT >
   {
      size_t operator() ( PointT const& point ) const
      {
         return ( ( point.first << 16 ) + point.second );
      }
   };
} // namespace std

int main()
{
   uint32_t N, M;
   std::cin >> N >> M;

   uint32_t K;
   std::cin >> K;

   std::unordered_set< PointT > diagonals;
   std::unordered_map< PointT, uint32_t > distance;
   for( uint32_t i = 0; i < K; ++i )
   {
      PointT point;
      std::cin >> point.first >> point.second;
      diagonals.insert( point );
      distance[ point ] = 0;
   }

   distance[ MakePoint(0, 0) ] = 0;

   std::unordered_set< PointT > processed;
   std::unordered_set< PointT > to_process;
   to_process.insert( MakePoint(0, 0) );

   auto get_next = [ & ]()
   {
      PointT result;
      uint32_t dst = 0;
      for( auto const& p : to_process )
      {
         auto const& d = distance[ p ];
         if( d >= dst )
         {
            dst = d;
            result = p;
         }
      }
      return result;
   };

   auto try_add_to_process = [ & ]( PointT const& point )
   {
      if( processed.find( point ) == processed.end() )
         to_process.insert( point );
   };

   auto process_point = [ & ]( PointT const& p1, PointT const& p2 )
   {
      uint32_t new_distance = distance[ p1 ] + 1;
      if( distance[ p2 ] < new_distance )
         distance[ p2 ] = new_distance;

      try_add_to_process( p2 );
   };

   while( !to_process.empty() )
   {
      PointT current_point = get_next();
      to_process.erase( current_point );
      processed.insert( current_point );

      for( auto const& p : diagonals )
      {
         if( p.first > current_point.first && p.second > current_point.second )
            process_point( current_point, p );
      }
   }

   uint32_t max_steps = 0;
   for( auto const& d : distance )
   {
      if( d.second > max_steps )
         max_steps = d.second;
   }

   double result = 100 * ( M + N - 2 * max_steps + sqrt( 2 ) * max_steps );

   std::cout << std::setprecision(0) << std::fixed << result << std::endl;

   return 0;
}
