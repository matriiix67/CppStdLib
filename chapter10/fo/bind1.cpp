//
// Created by Bourne on 2018/1/18.
//
#include <functional>
#include <iostream>

int main(int argc, char* argv[])
{
    auto plus10 = std::bind(std::plus<int>(), std::placeholders::_1, 10);
    std::cout << " + 10 = " << plus10(7) << std::endl;

    auto plus10times2 = std::bind(std::multiplies<int>(), std::bind(std::plus<int>(), std::placeholders::_1, 10), 2);

    std::cout << " + 10 * 2 = " << plus10times2(7) << std::endl;

    return 0;
}
