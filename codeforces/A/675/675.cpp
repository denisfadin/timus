// http://codeforces.com/problemset/problem/675/A

#include <iostream>

int main()
{
   long a, b, c;
   std::cin >> a >> b >> c;
   if( b==a || (c != 0 && (b-a)%c == 0 && (b-a)/c > 0) )
      std::cout << "YES";
   else
      std::cout << "NO";
   return 0;
}