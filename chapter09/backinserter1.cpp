//
// Created by Bourne on 2018/1/18.
//

#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int main(int argc, char* argv[])
{
    vector<int> coll;
    back_insert_iterator<vector<int>> iter(coll);
    *iter = 1;
    iter++;
    *iter = 2;
    iter++;
    *iter = 3;


    back_inserter(coll) = 44;
    back_inserter(coll) = 55;


    coll.reserve(2 * coll.size());
    copy(coll.begin(), coll.end(), back_inserter(coll));

    return 0;
}

