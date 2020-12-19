#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <vector>
#include <algorithm>

int main()
{
   std::vector< uint16_t > numbers( 10 );
   uint16_t max_number = 0;
   for( uint16_t i = 0; i < numbers.size(); ++i )
   {
      std::scanf( "%" SCNu16, &numbers[ i ] );
      max_number = std::max( max_number, numbers[ i ] );
   }

   std::vector< uint16_t > dividers( max_number + 1, 0 );

   std::vector< bool > prime_numbers( max_number + 1, true );
   prime_numbers[ 0 ] = prime_numbers[ 1 ] = false;
   for( uint16_t i = 2; i <= max_number; ++i )
   {
      if( !prime_numbers[ i ] )
         continue;
      for( uint16_t j = i * 2; j <= max_number; j += i )
         prime_numbers[ j ] = false;

      for( auto& num : numbers )
      {
         while( num % i == 0 )
         {
            dividers[ i ] += 1;
            num /= i;
         }
      }
   }

   uint16_t result = 1;
   for( auto const d : dividers )
      result = (result * (d + 1)) % 10;

   std::printf( "%" PRIu16 "\n", result );

   return 0;
}
