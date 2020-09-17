#include <iostream>
#include <vector>
#include <unordered_set>

int main()
{
  int N;
  std::cin >> N;

  long M;
  std::cin >> M;

  std::vector< std::vector< int > > deps;
  deps.resize( N );

  for( long i = 0; i < M; ++i )
  {
    int a, b;
    std::cin >> a >> b;
    deps[b-1].push_back( a-1 );
  }

  std::unordered_set< int > marked;

  for( int i = 0; i < N; ++i )
  {
    int a;
    std::cin >> a;

    std::vector< int > const& a_deps = deps[a-1];
    for( auto it = a_deps.begin(); it != a_deps.end(); ++it )
    {
      if( marked.find( *it ) == marked.end() )
      {
        std::cout << "NO";
        return 0;
      }
    }

    marked.insert( a-1 );
  }

  std::cout << "YES";

  return 0;
}
