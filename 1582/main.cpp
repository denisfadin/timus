#include <iostream>
#include <algorithm>
#include <iomanip>

int main()
{
   float k1, k2, k3;
   std::cin >> k1 >> k2 >> k3;

   float max = std::max( k1, k2 );
   max = std::max( max, k3 );

   float result = max * ( 1000 / ( max/k1 + max/k2 + max/k3 ) );

   std::cout << std::fixed << std::setprecision(0) << result << std::endl;

   return 0;
}
