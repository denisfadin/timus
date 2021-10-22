#include <iostream>
#include <cstdint>
#include <string>
#include <string_view>

int main()
{
  std::string s;
  std::getline( std::cin, s );

  auto check = [ & ]( size_t pos )
  {
    for( size_t i = pos, j = s.size()-1; i < j; ++i, --j )
      if( s[i] != s[j] )
        return false;
    return true;
  };

  size_t pos = 1;
  while( pos < s.size() )
  {
    if( check( pos ) )
      break;
    ++pos;
  }

  std::cout << s;
  do
  {
    --pos;
    std::cout << s[pos];
  } while( pos > 0 );

  std::cout << std::endl;

  return 0;
}
