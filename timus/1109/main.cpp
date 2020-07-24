#include <iostream>
#include <cstdint>
#include <vector>
#include <functional>

uint32_t maxMatching( uint32_t m, uint32_t n, std::vector< std::pair< uint32_t, uint32_t > > const& edges )
{
   std::vector< int32_t > pm( m, -1 );
   std::vector< int32_t > pn( n, -1 );

   std::function< bool( uint32_t, std::vector< bool >& ) > dfs = [&]( uint32_t x, std::vector< bool >& mis ) -> bool
   {
      if( mis[x] )
         return false;
      else
         mis[x] = true;

      for( auto const& edge : edges )
      {
         if( edge.first != x )
            continue;
         if( pn[edge.second] == -1 )
         {
            pn[edge.second] = edge.first;
            pm[edge.first] = edge.second;
            //std::cout << edge.first << " " << edge.second << std::endl;
            return true;
         }
         else if( dfs( pn[edge.second], mis ) )
         {
            pn[edge.second] = edge.first;
            pm[edge.first] = edge.second;
            //std::cout << edge.first << " " << edge.second << std::endl;
            return true;
         }
      }
      return false;
   };

   while( true )
   {
      bool path_finded = false;
      std::vector< bool > mis( m, false );
      for( uint32_t x = 0; x < m; ++x )
         if( pm[x] == -1 && dfs(x, mis) )
         {
            path_finded = true;
            break;
         }
      if( !path_finded )
         break;
   }
   uint32_t result = 0;
   for( auto e : pm )
      if( e != -1 )
         ++result;
   return result;
}

int main()
{
   uint32_t m, n, k;
   std::cin >> m >> n >> k;

   std::vector< std::pair< uint32_t, uint32_t > > edges;
   edges.resize( k );

   for( uint32_t i = 0; i < k; ++i )
   {
      std::cin >> edges[i].first >> edges[i].second;
      --edges[i].first;
      --edges[i].second;
   }

   std::cout << m + n - maxMatching( m, n, edges ) << std::endl;

   return 0;
}
