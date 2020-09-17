#include <iostream>
#include <cstdint>
#include <vector>

int main()
{
	uint16_t n;
	std::cin >> n;

	std::vector< std::pair<int32_t,int32_t> > v;
	v.resize( n );
	for( uint16_t i = 0; i < n; ++i )
		std::cin >> v[i].first >> v[i].second;

  uint16_t result = 2;
	for( uint16_t i = 0; i < n-1; ++i )
		for( uint16_t j = i+1; j < n; ++j )
		{
			uint16_t res = 2;
			for( uint16_t k = 0; k < n; ++k )
			{
				if( k == i || k == j )
					continue;

			  if( ( (v[i].second-v[j].second)*v[k].first + (v[j].first-v[i].first)*v[k].second + (v[i].first*v[j].second-v[j].first*v[i].second) ) == 0 )
					++res;
			}

			result = std::max( result, res );
		}

	std::cout << result << std::endl;
}
