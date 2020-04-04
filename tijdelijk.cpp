#include <fstream>
#include <iostream>
#include <algorithm>

bool is_empty(std::istream& in)
{
    return in.peek() == std::istream::traits_type::eof();
}

int main()
{
    std::ifstream file {"testFile.txt"};

    if (!is_empty(file)) {
        const auto minmax = minmax_stream<int>(file);

        std::cout << "min is " << minmax.first << std::endl;
        std::cout << "max is " << minmax.second << std::endl;
    } else {
        std::cout << "file is empty" << std::endl;
    }
}