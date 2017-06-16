#include <iostream>
#include <vector>

int main()
{
  long N;
  std::cin >> N;

  std::vector< int > num1, num2, sum;
  num1.resize( N );
  num2.resize( N );
  sum.resize( N );

  for( long i = 0; i < N; ++i )
  {
    int a, b;
    std::cin >> a >> b;
    num1[i] = a;
    num2[i] = b;
  }

  int s = 0;
  for( long i = N-1; i >= 0; --i )
  {
    s += num1[i] + num2[i];
    sum[i] = ( s > 9 ) ? s - 10 : s;

    s = ( s > 9 ) ? 1 : 0;
  }

  for( long i = 0; i < N; ++i )
     std::cout << sum[i];

  return 0;
}
