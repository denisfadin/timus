#include <cstdio>
#include <cstdint>
#include <cmath>

int main()
{
   int32_t v = 0, vd = 0;
   int32_t h = 0, hd = 0;

   char sym;
   while( std::scanf( "%c", &sym ) != EOF )
   {
      if( sym == '0' )
         break;
      else if( sym == '8' )
         ++v;
      else if( sym == '2' )
         --v;
      else if( sym == '6' )
         ++h;
      else if( sym == '4' )
         --h;
      else if( sym == '9' )
      {
         ++hd;
         ++vd;
      }
      else if( sym == '3' )
      {
         ++hd;
         --vd;
      }
      else if( sym == '7' )
      {
         --hd;
         ++vd;
      }
      else if( sym == '1' )
      {
         --hd;
         --vd;
      }
   }

   std::printf( "%.10f %.10f\n", h + hd*std::sqrt(2)/2, v + vd*std::sqrt(2)/2 );

   return 0;
}
