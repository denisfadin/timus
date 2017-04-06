// http://codeforces.com/problemset/problem/71/A

#include <iostream>
#include <string>

int main()
{
    int n;
    std::cin >> n;
    std::string s;
    s.reserve( 100 );
    for( int i = 0; i < n; ++i )
    {
        std::cin >> s;
        if( s.size() > 10 )
            std::cout << *s.begin() << s.size()-2 << *s.rbegin();
        else
            std::cout << s;
        std::cout << std::endl;
    }
    return 0;
}
