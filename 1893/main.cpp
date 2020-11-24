#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <string_view>

int main()
{
   uint16_t row;
   char seat;
   std::scanf( "%" SCNu16 "%c", &row, &seat );

   std::string_view result = "neither";
   if( row <= 2 )
   {
      if( seat == 'A' || seat == 'D' )
         result = "window";
      else
         result = "aisle";
   }
   else if( row <= 20 )
   {
      if( seat == 'A' || seat == 'F' )
         result = "window";
      else
         result = "aisle";
   }
   else
   {
      switch( seat )
      {
         case 'A':
         case 'K':
            result = "window";
            break;
         case 'C':
         case 'D':
         case 'G':
         case 'H':
            result = "aisle";
            break;
      }
   }

   std::printf( "%.*s\n", static_cast< int >( result.size() ), result.data() );

   return 0;
}
