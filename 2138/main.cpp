#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <array>

int main()
{
   std::array< char, 5 > type;
   std::scanf( "%s", type.data() );

   uint32_t num;
   std::scanf( "%" SCNu32, &num );

   uint32_t n1 = ( ( num & 0xFF000000 ) >> 24 );
   uint32_t n2 = ( ( num & 0x00FF0000 ) >> 16 );
   uint32_t n3 = ( ( num & 0x0000FF00 ) >> 8 );
   uint32_t n4 = ( ( num & 0x000000FF ) >> 0 );

   uint32_t result = (n4 << 24) + (n3 << 16) + (n2 << 8) + (n1 << 0);

   std::printf( "%" PRIu32 "\n", result );

   return 0;
}
