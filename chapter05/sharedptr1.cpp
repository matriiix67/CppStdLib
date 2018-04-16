//
// Created by Bourne on 2018/1/7.
//

#include <iostream>
#include <string>
#include <memory>
#include <vector>
using namespace std;

int main(int argc, char* argv[])
{
    shared_ptr<string> pNico(new string("nico"));
    shared_ptr<string> pJutta(new string("jutto"));

    (*pNico)[0] = 'N';
    pJutta->replace(0, 1, "j");

    vector<shared_ptr<string>> whoMadeCoffee;
    whoMadeCoffee.push_back(pJutta);
    whoMadeCoffee.push_back(pJutta);
    whoMadeCoffee.push_back(pNico);
    whoMadeCoffee.push_back(pJutta);
    whoMadeCoffee.push_back(pNico);

    for(auto ptr : whoMadeCoffee) {
        cout << *ptr << " ";
    }
    cout << endl;

    *pNico = "Nicolai";

    for(auto ptr : whoMadeCoffee) {
        cout << *ptr << " ";
    }
    cout << endl;

    cout << "use_count: " << whoMadeCoffee[0].use_count() << endl;

    return 0;
}
