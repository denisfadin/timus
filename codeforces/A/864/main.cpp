#include <cstdio>
#include <cinttypes>
#include <unordered_map>

int main()
{
   std::unordered_map< int16_t, int16_t > map;

   int16_t n;
   scanf( "%" SCNd16, &n );

   for( int i = 0; i < n; ++i )
   {
      int16_t x;
      scanf( "%" SCNd16, &x );

      if( map.find( x ) == map.end() )
         map[x] = 0;
      map[x]++;
   }

   if( map.size() == 2 )
   {
      auto it = map.begin();
      auto x1 = *it;
      ++it;
      auto x2 = *it;

      if( x1.second == x2.second )
      {
         printf( "YES\n%" PRId16 " %" PRId16 "\n", x1.first, x2.first );
         return 0;
      }
   }

   printf( "NO\n" );
   return 0;
}
