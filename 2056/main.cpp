#include <cstdint>
#include <cstdio>
#include <cinttypes>

int main()
{
   uint32_t N;
   std::scanf( "%" SCNu32, &N );

   uint32_t sum = 0;
   for( uint32_t i = 0; i < N; ++i )
   {
      uint32_t m;
      std::scanf( "%" SCNu32, &m );
      if( m == 3 )
      {
         std::printf( "None\n" );
         return 0;
      }
      sum += m;
   }

   if( sum / N == 5 )
   {
      std::printf( "Named\n" );
      return 0;
   }

   if( sum / static_cast< float > ( N ) >= 4.5f )
   {
      std::printf( "High\n" );
      return 0;
   }

   std::printf( "Common\n" );

   return 0;
}
