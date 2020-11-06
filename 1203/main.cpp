#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <vector>
#include <utility>
#include <algorithm>

int main()
{
   uint32_t N;
   std::scanf( "%" SCNu32, &N );

   using ReportT = std::pair< uint32_t, uint32_t >;
   std::vector< ReportT > reports( N );
   for( uint32_t i = 0; i < N; ++i )
      std::scanf( "%" SCNu32 "%" SCNu32, &reports[ i ].first, &reports[ i ].second );

   std::sort( reports.begin(), reports.end(), []( ReportT const& a, ReportT const& b )
   {
      return a.second < b.second;
   });

   std::vector< std::pair< uint32_t, uint32_t > > result;
   result.reserve( N + 1 );
   result.push_back( std::make_pair( 0, 0 ) );

   auto result_comp = []( std::pair< uint32_t, uint32_t > const& a, std::pair< uint32_t, uint32_t > const& b )
   {
      return a.first < b.first;
   };

   auto get_for = [ &result, &result_comp ]( uint32_t t )
   {
      auto it = std::upper_bound( result.begin(), result.end(), std::make_pair( t, 0 ), result_comp );
      return prev( it )->second;
   };

   for( auto const& rep : reports )
   {
      auto res = std::max( result.back().second, get_for( rep.first - 1 ) + 1 );
      if( result.back().first == rep.second )
         result.back().second = res;
      else
         result.push_back( std::make_pair( rep.second, res ) );
   }

   std::printf( "%" PRIu32 "\n", get_for( reports.back().second ) );

   return 0;
}
