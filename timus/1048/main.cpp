#include <iostream>
#include <vector>

int main()
{
  long N;
  std::cin >> N;

  std::vector< char > sum;
  sum.resize( N );

  for( long i = 0; i < N; ++i )
  {
    char a, b;
    std::cin >> a >> b;
    sum[i] = a - '0' + b - '0';
  }

  char s = 0;
  for( long i = N-1; i >= 0; --i )
  {
    sum[i] += s;
    if( sum[i] > 9 )
    {
      sum[i] -= 10;
      s = 1;
    }
    else
      s = 0;
  }

  for( long i = 0; i < N; ++i )
     std::cout << (char)(sum[i]+'0');

  return 0;
}
