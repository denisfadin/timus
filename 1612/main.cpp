#include <iostream>
#include <string>
#include <string_view>
#include <cstdint>
#include <cctype>

int main()
{
    constexpr std::string_view const TO_FIND{ "tr" };

    constexpr std::string_view const TRAM{ "tram" };
    constexpr std::string_view const TROLLEYBUS{ "trolleybus" };

    uint32_t tram = 0;
    uint32_t trolleybus = 0;

    std::string line;
    while( std::getline( std::cin, line ) )
    {
        std::string_view sv{ line };
        size_t pos = 0;
        while( true )
        {
            pos = sv.find( TO_FIND, pos );
            if( pos == std::string_view::npos )
                break;
            if( !sv.compare( pos, TRAM.size(), TRAM ) )
            {
                pos += TRAM.size();
                if( pos == sv.size() || !std::isalpha( sv.at( pos ) ) )
                    ++tram;
            }
            else if( !sv.compare( pos, TROLLEYBUS.size(), TROLLEYBUS ) )
            {
                pos += TROLLEYBUS.size();
                if( pos == sv.size() || !std::isalpha( sv.at( pos ) ) )
                    ++trolleybus;
            }
            else
                pos += TO_FIND.size();
        }
    }

    if( tram > trolleybus )
        std::cout << "Tram driver" << std::endl;
    else if( tram < trolleybus )
        std::cout << "Trolleybus driver" << std::endl;
    else
        std::cout << "Bus driver" << std::endl;

    return 0;
}
