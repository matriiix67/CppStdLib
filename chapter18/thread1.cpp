//
// Created by Bourne on 2018/1/8.
//
#include <thread>
#include <chrono>
#include <random>
#include <iostream>
#include <exception>
using namespace std;


void do_something(int num, char c) {
    try {
        default_random_engine dre(42 * c);
        uniform_int_distribution<int> id(10, 1000);
        for(int i = 0; i < num; ++i) {
            this_thread::sleep_for(chrono::milliseconds(id(dre)));
            cout.put(c).flush();
        }
    } catch (const exception& e) {
        cerr << "thread-exception (thread "
             << this_thread::get_id() << "):" << e.what() << endl;
    } catch(...) {
        cerr << "thread-exception (thread "
             << this_thread::get_id() << ")" << endl;
    }
}

int main(int argc, char* argv[])
{
    try {
        thread t1(do_something, 5, '.');
        cout << "- started fg thread " << t1.get_id() << endl;

        for(int i = 0; i < 5; ++i) {
            thread t(do_something, 10, 'a' + i);
            cout << "- detach started bg thread " << t.get_id() << endl;
            t.detach();
        }

        cin .get();

        cout << "- join fg thread " << t1.get_id() << endl;
        t1.join();
    } catch (const exception& e) {
        cerr << "EXCEPTION: " << e.what() << endl;
    }

    return 0;
}
