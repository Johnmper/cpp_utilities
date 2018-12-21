#ifndef __UL_CONTAINER_CIRCULAR_ARRAY_HPP
#define __UL_CONTAINER_CIRCULAR_ARRAY_HPP

#include <iostream>
#include <cstring>
#include <cstddef>

namespace ul{


    template<typename Type, std::size_t BufSize>
    class CircularArray{
    public:     // Members

        CircularArray() : idx_(0){
            std::memset(data_,'\0',BufSize*sizeof(Type));
        }

    private:    // Members

        std::size_t idx_;
        Type data_[BufSize];


    public:     // Methods

        /// Operator overload, usage for acces into the previously stored elements
        Type&
        operator [] ( std::size_t idx )
        {
            if( idx >= BufSize ){ std::cerr << "Element outside of array bounds!\n"; abort(); }
            idx += idx_;
            idx = ( idx >= BufSize ) ? idx-BufSize
                                     : idx;
            return data_[idx];
        }

        Type&
        add( const Type& element )
        {
            idx_ = (idx_ == 0)  ? BufSize-1
                                : idx_-1;

            data_[idx_] = element;
            return data_[idx_];
        }

    private:    // Methods

    };

}; // UL NAMESPACE

#endif // __UL_CONTAINER_CIRCULAR_ARRAY_HPP
