//
// Created by Bourne on 2018/1/18.
//
#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>

using namespace std;

class IntSequence {
private:
    int value;
public:
    IntSequence(int initialValue) : value(initialValue) {

    }

    int operator() () {
        return ++value;
    }
};


int main(int argc, char* argv[])
{
    list<int> coll;
    generate_n(back_inserter(coll), 0, IntSequence(1));

    generate(next(coll.begin()), prev(coll.end()), IntSequence(42));


    return 0;
}
