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


void do_something(char c)
{
    default_random_engine dre(c);
    uniform_int_distribution<int> id(10, 1000);

    for(int i = 0; i < 10; ++i) {
        this_thread::sleep_for(chrono::milliseconds(id(dre)));
        cout.put(c).flush();
    }
}

int main(int argc, char* argv[])
{
    cout << "starting 2 operations asynchronously" << endl;
    auto f1 = async([]{do_something('.'); });
    auto f2 = async([]{do_something('+'); });

    if(f1.wait_for(chrono::seconds(0)) != future_status::deferred ||
            f2.wait_for(chrono::seconds(0)) != future_status::deferred) {
        while(f1.wait_for(chrono::seconds(0)) != future_status::ready &&
                f2.wait_for(chrono::seconds()) != future_status::ready) {
            this_thread::yield();
        }
    }
    cout.put('\n').flush();

    try {
        f1.get();
        f2.get();
    } catch(const exception& e) {
        cout << "\nEXCEPTION: " << e.what() <<endl;
    }
    cout << "\ndone" << endl;
    return 0;
}
