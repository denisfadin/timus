// http://codeforces.com/problemset/problem/158/B

#include <iostream>
#include <algorithm>

int main()
{
   const long MAX_CNT = 100000;

   unsigned long n = 0;
   std::cin >> n;

   unsigned short mas[MAX_CNT];
   for( unsigned long i = 0; i < n; ++i )
      std::cin >> mas[i];

   std::sort( &mas[0], &mas[n], std::greater<int>() );

   unsigned long cnt = 0, i = 0;
   for( ; i < n; ++i, ++cnt )
      if( mas[i] != 4 )
         break;

   for( ; i < n; ++i, ++cnt )
   {
      if( mas[i] != 3 )
         break;
      if( mas[n-1] == 1 )
         --n;
   }

   short m = 0;
   for( ; i < n; ++i )
   {
      m += mas[i];
      if( m == 4 )
      {
         ++cnt;
         m = 0;
      }
   }

   if( m != 0 )
      ++cnt;

   std::cout << cnt << std::endl;
   
   return 0;
}
