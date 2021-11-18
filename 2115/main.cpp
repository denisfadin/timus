#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <vector>
#include <algorithm>

int main()
{
   uint32_t N;
   std::scanf( "%" SCNu32, &N );

   std::vector< uint32_t > data( N );
   for( uint32_t i = 0; i < N; ++i )
      std::scanf( "%" SCNu32, &data[ i ] );

   std::vector< uint32_t > new_data( data );

   std::sort( new_data.begin(), new_data.end() );
   std::vector< uint32_t > poses1;
   for( uint32_t i = 0; i < data.size(); ++i )
   {
      if( data[ i ] != new_data[ i ] )
      {
         poses1.push_back( i+1 );
         if( poses1.size() > 2 )
            break;
      }
   }

   std::sort( new_data.begin(), new_data.end(), std::greater<>() );
   std::vector< uint32_t > poses2;
   for( uint32_t i = 0; i < data.size(); ++i )
   {
      if( data[ i ] != new_data[ i ] )
      {
         poses2.push_back( i+1 );
         if( poses2.size() > 2 )
            break;
      }
   }

   if( poses1.size() > poses2.size() )
      poses1 = poses2;

   if( poses1.empty() )
      std::printf( "Nothing to do here\n" );
   else if( poses1.size() == 2 )
      std::printf( "Yes\n%" PRIu32 " %" PRIu32 "\n", poses1[ 0 ], poses1[ 1 ] );
   else
      std::printf( "No hope\n" );

   return 0;
}
