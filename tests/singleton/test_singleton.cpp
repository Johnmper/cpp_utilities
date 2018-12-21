#include <iostream>

#include <singleton.hpp>

struct A{
    void printPtr(){
        std::cout << "Type A: " << this << std::endl;
    }
};

struct B{
    void printPtr(){
        std::cout << "Type B: " << this << std::endl;
    }
};



void fooA(){
    ul::Singleton<A>::instance().printPtr();
}
void fooB(){
    fooA();
    ul::Singleton<B>::instance().printPtr();
}



int main(int argc, char** argv){

    std::cerr << "test_singleton\n";

    fooA();
    ul::Singleton<A>::instance().printPtr();
    fooB();
    ul::Singleton<B>::instance().printPtr();


    return 0;
}
