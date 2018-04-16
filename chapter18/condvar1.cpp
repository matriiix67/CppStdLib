//
// Created by Bourne on 2018/1/9.
//

#include <condition_variable>
#include <mutex>
#include <future>
#include <iostream>


bool read_flag;
std::mutex ready_mutex;
std::condition_variable ready_cond_var;

void thread1()
{
    std::cout << "<return>" << std::endl;
    std::cin.get();

    {
        std::lock_guard<std::mutex> lg(ready_mutex);
        read_flag = true;
    }
    ready_cond_var.notify_one();
}

void thread2()
{
    {
        std::unique_lock<std::mutex> ul(ready_mutex);
        ready_cond_var.wait(ul, []{return read_flag; });
    }

    std::cout << "done" << std::endl;
}


int main(int argc, char* argv[])
{
    auto f1 = std::async(std::launch::async, thread1);
    auto f2 = std::async(std::launch::async, thread2);
    return 0;
}
