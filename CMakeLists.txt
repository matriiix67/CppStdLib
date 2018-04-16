cmake_minimum_required(VERSION 3.9)
project(CppStdLib)

set(CMAKE_CXX_STANDARD 14)

add_executable(pair1 chapter05/pair1.cpp)
add_executable(tuple1 chapter05/tuple1.cpp)
add_executable(sharedptr1 chapter05/sharedptr1.cpp)
add_executable(sharedptr2 chapter05/sharedptr2.cpp)


add_executable(bind1 chapter10/fo/bind1.cpp)

add_executable(async1 chapter18/async1.cpp)
add_executable(async3 chapter18/async3.cpp)

add_executable(sharedfuture1 chapter18/sharedfuture1.cpp)
add_executable(thread1 chapter18/thread1.cpp)
add_executable(promise1 chapter18/promise1.cpp)
add_executable(mutex1 chapter18/mutex1.cpp)
add_executable(condvar1 chapter18/condvar1.cpp)



add_executable(other_thread1 other/thread1.cpp)