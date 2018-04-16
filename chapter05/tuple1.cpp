//
// Created by Bourne on 2018/1/4.
//

#include <iostream>
#include <tuple>
#include <complex>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
    tuple<string, int, int, complex<double>> t;
    tuple<int, float, string> t1(41, 6.3, "nico");

    cout << get<0>(t1) << " ";
    cout << get<1>(t1) << " ";
    cout << get<2>(t1) << " ";
    cout << endl;

    auto t2 = make_tuple(22, 44, "nico");

    get<1>(t1) = get<1>(t2);

    if(t1 < t2) {
        t1 = t2;
    }

    double second_elem;
    tie(std::ignore, second_elem, std::ignore) = t2;

    return 0;
}
