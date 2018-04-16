//
// Created by Bourne on 2018/1/9.
//

#include <future>
#include <mutex>
#include <iostream>
#include <string>

std::mutex print_mutex;

void print(const std::string &s) {
    std::lock_guard<std::mutex> l(print_mutex);
    for(char c: s) {
        std::cout.put(c);
    }
    std::cout << std::endl;
}

int main(int argc, char* argv[])
{
    auto f1 = std::async(std::launch::async, print, "hello from a first thread");
    auto f2 = std::async(std::launch::async, print, "hello from a second thread");
    print("hello from the main thread");
    return 0;
}
