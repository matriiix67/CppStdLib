//
// Created by Bourne on 2018/1/7.
//

#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class Person {
public:
    string name;
    shared_ptr<Person> mother;
    shared_ptr<Person> father;
    vector<shared_ptr<Person>> kids;

    Person(const string& n, shared_ptr<Person> m = nullptr, shared_ptr<Person> f = nullptr) : name(n), mother(m), father(f) {}
    ~Person() {
        cout << "delete " << name << endl;
    }
private:

};
