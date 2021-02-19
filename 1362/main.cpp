#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <vector>
#include <limits>
#include <algorithm>

uint32_t DP( uint32_t key, std::vector< std::vector< uint32_t > > const& kids )
{
   auto const& key_kids = kids[ key ];
   if( key_kids.empty() )
      return 0;

   std::vector< uint32_t > kids_values;
   kids_values.reserve( key_kids.size() );

   for( auto const& kid : key_kids )
      kids_values.push_back( DP( kid, kids ) );

   std::sort( kids_values.begin(), kids_values.end(), std::greater() );

   uint32_t result = 1;
   uint32_t last_steps = kids_values[ 0 ];
   for( uint32_t i = 1; i < kids_values.size(); ++i )
   {
      ++result;
      if( last_steps > 0 )
         last_steps = std::max( last_steps - 1, kids_values[ i ] );
      else
         last_steps = kids_values[ i ];
   }

   return result + last_steps;
}

int main()
{
   uint32_t N;
   std::scanf( "%" SCNu32, &N );

   std::vector< uint32_t > data( N + 1, std::numeric_limits< uint32_t >::max() );

   for( uint32_t i = 1; i <= N; ++i )
   {
      while( true )
      {
         uint32_t s;
         std::scanf( "%" SCNu32, &s );
         if( s == 0 )
            break;
         data[ s ] = i;
      }
   }

   uint32_t T;
   std::scanf( "%" SCNu32, &T );

   // немного модифицируем дерево чтоб Таня стала его корнем
   {
      uint32_t tmp = data[ T ];
      data[ T ] = std::numeric_limits< uint32_t >::max();
      uint32_t tmp_root = T;
      while( tmp != std::numeric_limits< uint32_t >::max() )
      {
         uint32_t t = data[ tmp ];
         data[ tmp ] = tmp_root;
         tmp_root = tmp;
         tmp = t;
      }
   }

   std::vector< std::vector< uint32_t > > kids( N + 1 );

   for( uint32_t i = 1; i <= N; ++i )
   {
      if( data[ i ] == std::numeric_limits< uint32_t >::max() )
         continue;
      kids[ data[ i ] ].push_back( i );
   }

   std::printf( "%" PRIu32 "\n", DP( T, kids ) );

   return 0;
}
