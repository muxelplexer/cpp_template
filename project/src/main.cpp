#include <iostream>
#include "event.hpp"
int main()
{
    static event test {0, "VITE pres. AKOV", "VITE", {"AKOV", "Pluvio", "Screamarts"}};

    std::cout << test.to_string() << "\n";
    for(const auto artist : test.artists())
    {
        std::cout << std::format("\t- {}\n", artist);
    }


    return 42;
}