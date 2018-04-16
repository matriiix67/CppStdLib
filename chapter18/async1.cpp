//
// Created by Bourne on 2018/1/8.
//

#include <future>
#include <thread>
#include <chrono>
#include <random>
#include <iostream>
#include <exception>

using namespace std;

int do_something(char c)
{
    std::default_random_engine dre(c);
    std::uniform_int_distribution<int> id(10, 1000);

    for(int i = 0; i < 10; ++i) {
        this_thread::sleep_for(chrono::milliseconds(id(dre)));
        cout.put(c).flush();
    }

    return c;
}


int func1()
{
    return do_something('.');
}

int func2()
{
    return do_something('+');
}


int main(int argc, char* argv[])
{
    std::cout << "starting func1() in background"
              << " and func2() in foreground:" << std::endl;

    std::future<int> result1 = std::async(std::launch::async, func1);
    int result2 = func2();

    int result = result1.get() + result2;
    std::cout << "\nresult of func1() + func2() :" << result << std::endl;
    return 0;
}
