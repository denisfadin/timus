#include <cstdint>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

std::vector< int32_t > factorize( int32_t n )
{
   std::vector< int32_t > result;

   for( int32_t i = 2; i <= std::sqrt(n); ++i )
      while( n % i == 0 )
      {
         result.push_back( i );
         n /= i;
      }

   if( n != 1 || result.size()==0 )
      result.push_back( n );

   return result;
}

int main()
{
   int32_t n;
   std::cin >> n;

   auto factors = factorize( n );

   while( true )
   {
      std::sort( std::begin( factors ), std::end( factors ) );

      if( factors.size() < 2 )
         break;

      auto d = factors[0] * factors[1];
      if( d > 9 )
         break;

      factors.erase( factors.begin(), factors.begin()+2 );
      factors.emplace_back( std::move( d ) );
   }

   for( auto const& c : factors )
      std::cout << c;
   std::cout << std::endl;

   return 0;
}
