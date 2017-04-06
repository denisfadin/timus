// http://codeforces.com/problemset/problem/513/B1

#include <iostream>

int f( int* A, int N )
{
   int sum = 0;
   for( int i = 0; i < N; ++i )
      for( int j = i; j < N; ++j )
      {
         int min = A[i];
         for( int k = i+1; k <= j; ++k )
            if( min > A[k] )
               min = A[k];
         sum += min;
      }
   return sum;
}

//
// Алгоритм Нарайаны
//
void Narayana( int* A, int N )
{
   int j = N-2;
   
   if( j < 0 )
      return;
   
   while( j >= 0 && A[j] >= A[j+1] )
      --j;
   
   int l = N-1;
   while( A[j] >= A[l] )
      --l;
   
   int tmp = A[j];
   A[j] = A[l];
   A[l] = tmp;
   
   
   for( int i = j+1, k = N-1; i < k; ++i, --k )
   {
      tmp = A[i];
      A[i] = A[k];
      A[k] = tmp;
   }
}

int main()
{
   const int MAX_CNT = 8;
   int A[ MAX_CNT ];
   
   int N, M;
   std::cin >> N >> M;
   
   
   for( int i = 0; i < N; ++i )
      A[i] = i+1;
   
   int sum = f( A, N );

   int i = 1;
   while( i < M )
   {
      Narayana( A, N );
      if( sum == f( A, N ) )
         ++i;
   }
      
   for( int j = 0; j < N; ++j )
      std::cout << A[j] << " ";
   std::cout << std::endl;
   
   return 0;
}