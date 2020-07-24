#include <iostream>

int main()
{
   int n, p1, p2, p3, t1, t2;
   std::cin >> n >> p1 >> p2 >> p3 >> t1 >> t2;

   int l, r;
   std::cin >> l >> r;

   long result = (r - l)*p1;

   for( int i = 1; i < n; ++i )
   {
      int ln, rn;
      std::cin >> ln >> rn;

      result += std::min( t1, ln - r ) * p1;
      if( r + t1 < ln )
         result += std::min( t2, ln - r - t1 ) * p2;
      if( r + t1 + t2 < ln )
         result += ( ln - r - t1 - t2 ) * p3;

      result += (rn - ln)*p1;

      l = ln;
      r = rn;
   }

   std::cout << result << std::endl;

   return 0;
}
