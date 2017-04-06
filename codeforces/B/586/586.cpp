// http://codeforces.com/problemset/problem/586/B

#include <iostream>
#include <algorithm> 

int main()
{
   const int MAX_N = 50;
   
   int N;
   std::cin >> N;
   
   int a1[MAX_N];
   a1[0] = 0;
   for( int i = 1; i < N; ++i )
   {
      std::cin >> a1[i];
      a1[i] += a1[i-1];
   }
   
   int a2[MAX_N];
   for( int i = 0; i < N-1; ++i )
      std::cin >> a2[i];
   a2[N-1] = 0;
   
   for( int i = N-1; i > 0; --i )
      a2[i-1] += a2[i];
      
   int tmp = 0;
   for( int i = 0; i < N; ++i )
   {
      std::cin >> tmp;
      a1[i] += tmp;
      a1[i] += a2[i];
   }
      
   std::sort( a1, a1 + N );
      
   std::cout << a1[0]+a1[1] << std::endl;
   
   return 0;
}