#include <iostream>

#include <log/core.hpp>

class A{
public:
    int n=0;

    A(int _n) : n(_n){}

};


int main(int argc, char** argv){
    std::cerr << "test_log_core\n";

    //auto tt = ul::Singleton<ul::Logger>::instance();
    // std::cout << "Pointer to logger: " << (*tt).n << std::endl;
    //
    //
    // int ii = 1;
    // A tmp1(1);
    // (&tmp1) << 1;

    ul::Log(ul::info) << 2 << std::endl;
    ul::Log(ul::warn) << 2 << std::endl;
    ul::Log(ul::fatal) << 2 << std::endl;

    return 0;
}
