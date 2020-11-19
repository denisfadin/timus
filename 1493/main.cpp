#include <cstdint>
#include <cstdio>
#include <cinttypes>

int main()
{
   uint32_t number;
   std::scanf( "%" SCNu32, &number );

   auto next_number = ( number + 1 ) % 1000000;
   auto prev_number = number == 0 ? 999999 : ( number - 1 ) % 1000000;

   auto dsum = []( uint32_t n )
   {
      uint32_t result = 0;
      for( uint32_t i = 0; i < 3; ++i )
      {
         result += n % 10;
         n /= 10;
      }
      return result;
   };

   auto check = [ &dsum ]( uint32_t n )
   {
      uint32_t n1 = n / 1000;
      uint32_t n2 = n1 != 0 ? n % ( n1 * 1000 ) : n;
      return dsum( n1 ) == dsum( n2 );
   };

   if( check( next_number ) || check( prev_number ) )
      std::printf( "Yes\n" );
   else
      std::printf( "No\n" );

   return 0;
}
