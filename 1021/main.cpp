#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <vector>

int main()
{
   uint16_t N1;
   std::scanf( "%" SCNu16, &N1 );

   std::vector< int16_t > list1( N1, 0 );
   for( uint16_t i = 0; i < N1; ++i )
      std::scanf( "%" SCNd16, &list1[ i ] );

   bool result = false;

   uint16_t N2;
   std::scanf( "%" SCNu16, &N2 );

   int32_t num2;
   std::scanf( "%" SCNd32, &num2 );

   uint16_t idx1 = 0, idx2 = 0;
   while( true )
   {
      int32_t sum = num2 + static_cast< int32_t >( list1[ idx1 ] );
      if( sum == 10000 )
      {
         result = true;
         break;
      }
      else if( sum < 10000 )
      {
         ++idx1;
         if( idx1 == N1 )
            break;
      }
      else
      {
         ++idx2;
         if( idx2 == N2 )
            break;
         std::scanf( "%" SCNd32, &num2 );
      }
   }

   std::printf( result ? "YES\n" : "NO\n" );

   return 0;
}
