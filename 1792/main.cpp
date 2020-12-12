#include <cstdint>
#include <cstdio>
#include <cinttypes>

#ifndef SCNu8
  #define SCNu8 "hhu"
#endif
#ifndef PRIu8
  #define PRIu8 "hhu"
#endif

int main()
{
   uint8_t i1, i2, i3, i4, r1, r2, r3;
   std::scanf( "%" SCNu8 "%" SCNu8 "%" SCNu8 "%" SCNu8
               "%" SCNu8 "%" SCNu8 "%" SCNu8,
                &i1, &i2, &i3, &i4,
                &r1, &r2, &r3 );

   uint8_t result = 0;

   if( ( i1 + i2 + i4 + r3 ) % 2 )
      result |= ( 1 << 2 );

   if( ( i1 + i3 + i4 + r2 ) % 2 )
      result |= ( 1 << 1 );

   if( ( i2 + i3 + i4 + r1 ) % 2 )
      result |= ( 1 << 0 );

   switch( result )
   {
      case 6:
         i1 = !i1;
         break;
      case 5:
         i2 = !i2;
         break;
      case 3:
         i3 = !i3;
         break;
      case 7:
         i4 = !i4;
         break;
      case 1:
         r1 = !r1;
         break;
      case 2:
         r2 = !r2;
         break;
      case 4:
         r3 = !r3;
         break;
   }

   std::printf( "%" PRIu8 " %" PRIu8 " %" PRIu8 " %" PRIu8
                " %" PRIu8 " %" PRIu8 " %" PRIu8 "\n",
                i1, i2, i3, i4,
                r1, r2, r3 );

   return 0;
}
