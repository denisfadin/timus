#include <cstdint>
#include <cstdio>
#include <cinttypes>

int main()
{
   uint16_t N, T, S;
   std::scanf( "%" SCNu16 "%" SCNu16 "%" SCNu16, &N, &T, &S );

   for( uint16_t i = 0; i < N; ++i )
   {
      uint16_t s;
      std::scanf( "%" SCNu16, &s );

      std::printf( "%.6lf\n", static_cast< double >( s + S + T ) / 2 );
   }

   return 0;
}
