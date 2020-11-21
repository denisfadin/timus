#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <vector>
#include <cmath>

int main()
{
   uint32_t N;
   std::scanf( "%" SCNu32, &N );

   uint32_t all_juice_amount = 0;
   std::vector< uint32_t > juice_amount( N, 0 );
   for( uint32_t i = 0; i < N; ++i )
   {
      std::scanf( "%" SCNu32, &juice_amount[ i ] );
      all_juice_amount += juice_amount[ i ];
   }

   double person_juice_amount = static_cast< double >( all_juice_amount ) / ( juice_amount.size() + 1 );
   uint32_t complaining_persons = 0;
   double complaining_amount = 0;
   for( uint32_t i = 0; i < N; ++i )
   {
      double diff = static_cast< double >( juice_amount[ i ] ) - person_juice_amount;
      if( diff > 0 )
      {
         ++complaining_persons;
         complaining_amount += diff;
      }
   }

   double money_amount = 100.0l;
   for( uint32_t i = 0; i < N; ++i )
   {
      double diff = static_cast< double >( juice_amount[ i ] ) - person_juice_amount;
      if( diff > 0 )
      {
         auto result = money_amount * diff / complaining_amount;
         std::printf( "%" PRIu32 " ", static_cast< uint32_t >( result + 1e-10 ) );
      }
      else
         std::printf( "0 " );
   }
   std::printf( "\n" );

   return 0;
}
