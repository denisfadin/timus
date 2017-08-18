#include <iostream>
#include <stdint.h>
#include <vector>
#include <algorithm>

int main()
{
   int32_t m;
   std::cin >> m;

   std::vector< std::pair< int32_t, int32_t > > A( m ), B( m );

   for( int32_t i = 0; i < m; ++i )
      std::cin >> A[i].first;

   for( int32_t i = 0; i < m; ++i )
   {
      std::cin >> B[i].first;
      B[i].second = i;
   }

   std::sort( A.begin(), A.end(), []( std::pair< int32_t, int32_t > const& a, std::pair< int32_t, int32_t > const& b ){
      return a.first < b.first;
   });

   std::sort( B.begin(), B.end(), []( std::pair< int32_t, int32_t > const& a, std::pair< int32_t, int32_t > const& b ){
      return a.first > b.first;
   });

   for( int32_t i = 0; i < m; ++i )
      A[i].second = B[i].second;

   std::sort( A.begin(), A.end(), []( std::pair< int32_t, int32_t > const& a, std::pair< int32_t, int32_t > const& b ){
      return a.second < b.second;
   });

   for( int32_t i = 0; i < m; ++i )
      std::cout << A[i].first << " ";
   std::cout << std::endl;
}
