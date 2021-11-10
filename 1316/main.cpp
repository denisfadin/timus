#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <set>

int main()
{
   uint64_t count = 0;

   std::multiset< float > data;

   char buf[ 5 ];
   while( true )
   {
      std::scanf( "%s", &buf );
      if( buf[ 0 ] == 'B' ) // BID X
      {
         float x;
         std::scanf( "%f", &x );

         data.insert( x );
      }
      else if( buf[ 0 ] == 'D' ) // DEL X
      {
         float x;
         std::scanf( "%f", &x );

         data.erase( data.find( x ) );
      }
      else if( buf[ 0 ] == 'S' ) // SALE X K
      {
         float x;
         uint32_t k;
         std::scanf( "%f %" SCNu32, &x, &k );

         auto it = data.lower_bound( x );
         count += std::min( k, static_cast< uint32_t >( std::distance( it, data.end() ) ) );
      }
      else // QUIT
         break;
   }

   double result = count;
   result /= 100;
   std::printf( "%.2lf\n", result );

   return 0;
}
