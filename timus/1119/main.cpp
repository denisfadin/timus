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
   for( uint32_t i = 0; i < K; ++i )
   {
      PointT point;
      std::cin >> point.first >> point.second;
      diagonals.insert( point );
   }

   std::unordered_map< PointT, double > distance;
   distance[ MakePoint(0, 0) ] = 0;

   std::unordered_set< PointT > processed;
   std::unordered_set< PointT > to_process;
   to_process.insert( MakePoint(0, 0) );

   auto get_next = [ & ]()
   {
      PointT result;
      double min_distance = std::numeric_limits< double >::max();
      for( auto const& p : to_process )
      {
         auto const& d = distance[ p ];
         if( d <= min_distance )
         {
            min_distance = d;
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

   auto process_point = [ & ]( PointT const& p1, PointT const& p2, double delta )
   {
      double new_distance = distance[ p1 ] + delta;
      if( distance.find( p2 ) == distance.end() )
         distance[ p2 ] = new_distance;
      else if( distance[ p2 ] > new_distance )
         distance[ p2 ] = new_distance;

      try_add_to_process( p2 );
   };

   while( !to_process.empty() )
   {
      PointT current_point = get_next();
      to_process.erase( current_point );
      processed.insert( current_point );

      if( current_point.first < N )
      {
         PointT p = current_point;
         p.first += 1;
         process_point( current_point, p, 100 );
      }

      if( current_point.second < M )
      {
         PointT p = current_point;
         p.second += 1;
         process_point( current_point, p, 100 );
      }

      {
         PointT p = current_point;
         p.first += 1;
         p.second += 1;
         if( diagonals.find( p ) != diagonals.end() )
            process_point( current_point, p, 100*sqrt(2) );
      }
   }

   std::cout << std::setprecision(0) << std::fixed << distance[ MakePoint(N, M) ] << std::endl;

   return 0;
}
