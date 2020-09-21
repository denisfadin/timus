#include <iostream>
#include <map>

int main()
{
  struct Data
  {
    int T2;
    int T3;
  };

  std::map< int, Data > M;

  int N, T1;
  std::cin >> N;
  for( int i = 0; i < N; ++i )
  {
    Data d;
    std::cin >> T1 >> d.T2 >> d.T3;
    M.emplace( T1, std::move( d ) );
  }

  int m = 0, t = 0;
  for( auto it = M.begin(); it != M.end(); ++it )
  {
    m = std::max( m, it->first ) + it->second.T2;
    t = std::max( m - it->second.T3, t );
  }
  std::cout << t;
  return 0;
}
