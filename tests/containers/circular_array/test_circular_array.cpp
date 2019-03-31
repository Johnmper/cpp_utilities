#include <iostream>
#include <numeric>
#include <functional>

#include <containers/circular_array.hpp>

template<typename Type, std::size_t Size>
void printMemOrder( const ul::CircularArray<Type,Size>& circ_array )
{
    Type total = 0;
    std::cout << " Memory Order:\n    ( ";
    for(std::size_t kk = 0; kk < Size; ++kk){
        std::cout << circ_array(kk) << " ";
        total +=  circ_array(kk);
    }
    std::cout << ") Total: " << total << std::endl;
}

template<typename Type, std::size_t Size>
void printAccessOrder( const ul::CircularArray<Type,Size>& circ_array )
{
    std::cout << " Array Order:\n    [ ";
    for(std::size_t kk = 0; kk < circ_array.size(); ++kk){
        std::cout << circ_array.at(kk) << " ";
    }
    std::cout << "]" << std::endl;
}


int main(int arc, char** argv)
{
    std::cerr << "test_containers_circular_array\n";

    ul::CircularArray<int,8> buf;
    std::cout << " Size: " << buf.size() << std::endl;


    for(auto it : buf){ std::cout << it << " "; }   // Loop variable by value

    for(int ii=1; ii<=10 ;++ii){
        buf.add(ii);
        std::cout << "Add "<< ii << std::endl;
    }
    std::cout << " Size: " << buf.size() << std::endl;
    printMemOrder(buf);
    printAccessOrder(buf);

    // Iterators Usage:
    // ul::CircularArray<Type,Size>::Iterator
    // ul::CircularArray<Type,Size>::ConstIterator

    std::cout << " Test For Loops!\n";
    std::cout << "   Typical For Loop:\n    [ ";
    for(int kk=0; kk < buf.size(); ++kk){ std::cout << buf[kk] << " "; }
    std::cout << "]" << std::endl;

    std::cout << "   Iterators For Loop:\n    [ ";
    for(auto it=buf.begin(); it != buf.end(); ++it){ std::cout << *it << " "; }
    std::cout << "]" << std::endl;

    std::cout << "   Range For Loops:\n    [ ";
    for(auto it : buf){ std::cout << it << " "; }   // Loop variable by value
    std::cout << "]" << std::endl;

    std::cout << "    [ ";
    for(const auto it : buf){ std::cout << it << " "; } // Loop variable by const value
    std::cout << "]" << std::endl;

    std::cout << "    [ ";
    for(auto& it : buf){ std::cout << it << " "; }  // Loop variable by reference
    std::cout << "]" << std::endl;

    std::cout << "    [ ";
    for(const auto& it : buf){ std::cout << it << " "; }    // Loop variable by const reference
    std::cout << "]" << std::endl;


    // Creation of a const object of our buffer
    const auto& const_buf = buf;
    std::cout << " With const object!\n";

    std::cout << "   Range For Loops:\n    [ ";
    for(auto it : const_buf){ std::cout << it << " "; }
    std::cout << "]" << std::endl;

    std::cout << "    [ ";
    for(const auto it : const_buf){ std::cout << it << " "; }
    std::cout << "]" << std::endl;

    std::cout << "    [ ";
    for(auto& it : const_buf){ std::cout << it << " "; }
    std::cout << "]" << std::endl;

    std::cout << "    [ ";
    for(const auto& it : const_buf){ std::cout << it << " "; }
    std::cout << "]" << std::endl;

    // Testing STL algorithms
    std::cout << "std::accumulate() = " << std::accumulate(buf.begin(), buf.end(), 0) << std::endl;
    return 0;
}
