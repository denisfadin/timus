#include <cstdint>
#include <cstdio>
#include <cinttypes>

int main()
{
   uint16_t T1, T2;
   std::scanf( "%" SCNu16 "%" SCNu16, &T1, &T2 );

   for( uint16_t i = 0; i < 10; ++i )
   {
      uint16_t recalls;
      std::scanf( "%" SCNu16, &recalls );

      T2 -= 20*recalls;
   }

   std::printf( T2 < T1 ? "Dirty debug :(\n" : "No chance.\n" );

   return 0;
}
