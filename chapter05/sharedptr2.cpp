//
// Created by Bourne on 2018/1/7.
//

#include <string>
#include <fstream>
#include <memory>
#include <cstdio>

class FileDeleter {
public:
    FileDeleter(const std::string& fn) : filename_(fn) { }
    void operator()(std::ofstream* fp) {
        fp->close();
        std::remove(filename_.c_str());
    }
private:
    std::string filename_;
};


int main(int argc, char* argv[])
{
    std::shared_ptr<std::ofstream> fp(new std::ofstream("tmpfile.txt"), FileDeleter("tmpfile.txt"));
    return 0;
}
