//
// Created by Bourne on 2018/1/7.
//

#include <iostream>
#include <string>
#include <memory>
#include <dirent.h>
#include <cstring>
#include <cerrno>
using namespace std;

class DirCloser {
public:
    void operator() (DIR* dp) {
        if(closedir(dp) != 0) {
            std::cerr << "OOPS: closedir() failed" << std::endl;
        }
    }
private:
};


int main(int argc, char* argv[])
{
    unique_ptr<DIR, DirCloser> p_dir(opendir("."));

    struct dirent* dp;
    while((dp = readdir(p_dir.get())) != nullptr) {
        string filename(dp->d_name);
        cout << "process " << filename << endl;
    }
    return 0;
}