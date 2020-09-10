#include <iostream>
#include <cinttypes>
#include <vector>
#include <unordered_map>
#include <iomanip>
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

uint32_t CalcSteps( PointT const& p, std::vector< PointT > const& diagonals )
{
   static std::unordered_map< PointT, uint32_t > steps;

   auto it = steps.find( p );
   if( it != steps.end() )
      return it->second;

   uint32_t result = 0;
   for( auto const& next : diagonals )
   {
      if( next.first <= p.first || next.second <= p.second )
         continue;

      auto steps = CalcSteps( next, diagonals );
      if( result < steps )
         result = steps;
   }

   result += 1;

   steps[ p ] = result;
   return result;
}

int main()
{
   uint32_t N, M;
   std::cin >> N >> M;

   uint32_t K;
   std::cin >> K;

   std::vector< PointT > diagonals;
   for( uint32_t i = 0; i < K; ++i )
   {
      PointT point;
      std::cin >> point.first >> point.second;
      diagonals.push_back( point );
   }

   uint32_t max_steps = 0;
   for( auto const& p : diagonals )
   {
      uint32_t steps = CalcSteps( p, diagonals );
      if( max_steps < steps )
         max_steps = steps;
   }

   double result = 100 * ( M + N - 2 * max_steps + sqrt( 2 ) * max_steps );

   std::cout << std::setprecision(0) << std::fixed << result << std::endl;

   return 0;
}
