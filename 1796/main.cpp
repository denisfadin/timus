#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <array>

int main()
{
   constexpr std::array< uint16_t, 6 > const notes = {
      10,
      50,
      100,
      500,
      1000,
      5000
   };

   std::array< uint16_t, 6 > notes_count;
   for( uint16_t i = 0; i < notes.size(); ++i )
      std::scanf( "%" SCNu16, &notes_count[ i ] );

   uint16_t price;
   std::scanf( "%" SCNu16, &price );

   auto get_next = [ & ]() -> uint16_t
   {
      for( int16_t i = notes_count.size() - 1; i >= 0; --i )
         if( notes_count[ i ] )
         {
            --notes_count[ i ];
            return notes[ i ];
         }
      return 0;
   };

   uint32_t result_min = 0, result_max = 0, sum = 0;

   while( true )
   {
      uint16_t next = get_next();
      if( !next )
         break;
      sum += next;

      if( sum - result_max * price >= price )
         result_min = result_max + 1;
      result_max = sum / price;
   }

   std::printf( "%" PRIu32 "\n", result_max - result_min + 1 );
   for( uint32_t i = result_min; i <= result_max; ++i )
      std::printf( "%" PRIu32 " ", i );
   std::printf( "\n" );

   return 0;
}
