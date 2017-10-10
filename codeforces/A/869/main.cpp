#include <cstdio>
#include <cinttypes>
#include <vector>
#include <unordered_set>

int main()
{
   int32_t n;
   scanf( "%" SCNd32, &n );

   std::unordered_set< int32_t > nums;
   nums.reserve( n << 1 );

   std::vector< int32_t > x( n ), y( n );
   for( int32_t i = 0; i < n; ++i )
      scanf( "%" SCNd32, &x[i] );
   for( int32_t i = 0; i < n; ++i )
      scanf( "%" SCNd32, &y[i] );

   int32_t result = 0;
   for( int32_t i = 0; i < n; ++i )
      for( int32_t j = 0; j < n; ++j )
      {
         if( nums.find( x[i] ^ y[j] ) != nums.end() )
            ++result;
      }

   printf( result % 2 ? "Koyomi\n" : "Karen\n" );

   return 0;
}
