#include <cstdint>
#include <cstdio>
#include <cinttypes>

int main()
{
   uint16_t N;
   std::scanf( "%" SCNu16, &N );

   uint32_t result = 0;
   for( uint16_t i = 0; i < N; ++i )
   {
      uint16_t nuts;
      std::scanf( "%" SCNu16, &nuts );
      result += ( ( nuts - 1 ) >> 1 );
   }

   std::printf( result % 2 ? "Daenerys\n" : "Stannis\n" );

   return 0;
}
