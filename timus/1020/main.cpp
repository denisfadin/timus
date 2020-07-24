#include <iostream>
#include <cstdint>
#include <vector>
#include <cmath>
#include <iomanip>

double const pi = std::acos( -1 );

float distance( float const& x1, float const& y1, float const& x2, float const& y2 )
{
   return std::sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) );
}

float circumference( float const& r )
{
   return 2 * pi * r;
}

int main()
{
   uint16_t N;
   std::cin >> N;

   float R;
   std::cin >> R;

   std::vector< std::pair< float, float > > buf;
   buf.reserve( N );
   for( uint16_t i = 0; i < N; ++i )
   {
      float a, b;
      std::cin >> a >> b;
      buf.emplace_back( std::make_pair( std::move(a), std::move(b) ) );
   }

   float result = 0;
   for( uint16_t i = 1; i < N; ++i )
      result += distance( buf[i].first, buf[i].second, buf[i-1].first, buf[i-1].second );
   result += distance( buf[N-1].first, buf[N-1].second, buf[0].first, buf[0].second );

   result += circumference( R );

   std::cout << std::fixed << std::setprecision(2) << result << std::endl;

   return 0;
}
