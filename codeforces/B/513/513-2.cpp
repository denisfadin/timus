// http://codeforces.com/problemset/problem/513/B2

#include <iostream>

void Print( int* A, int N )
{
   for( int j = 0; j < N; ++j )
      std::cout << A[j] << " ";
   std::cout << std::endl;
}

int main()
{
   const int MAX_CNT = 50;
   int A[ MAX_CNT ];
   
   int N;
   long long M;
   std::cin >> N >> M;
   
   long long n = 1LL << (N-1), m = M;
   int k1 = 0, k2 = N-1;
   for( long long i = 0; i < N; ++i )
   {
      n >>= 1;
      A[ ( m <= n ) ? k1++ : k2-- ] = i+1;
      if( m > n )
         m -= n;
   }

   Print( A, N );
   
   return 0;
}