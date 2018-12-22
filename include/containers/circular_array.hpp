#ifndef __UL_CONTAINER_CIRCULAR_ARRAY_HPP
#define __UL_CONTAINER_CIRCULAR_ARRAY_HPP

#include <iostream>
#include <exception>
#include <cstring>
#include <cstddef>

namespace ul{

//===========================================================================================================
//    #####                                                 #
//   #     # # #####   ####  #    # #        ##   #####    # #   #####  #####    ##   #   #
//   #       # #    # #    # #    # #       #  #  #    #  #   #  #    # #    #  #  #   # #
//   #       # #    # #      #    # #      #    # #    # #     # #    # #    # #    #   #
//   #       # #####  #      #    # #      ###### #####  ####### #####  #####  ######   #
//   #     # # #   #  #    # #    # #      #    # #   #  #     # #   #  #   #  #    #   #
//    #####  # #    #  ####   ####  ###### #    # #    # #     # #    # #    # #    #   #
//===========================================================================================================
    template<typename Type, std::size_t const Size>
    class CircularArray{

    private:    // Members

        std::size_t begin_idx_;
        std::size_t end_idx_;
        std::size_t size_;
        Type        data_[Size];
    public:     // Members
        CircularArray() : begin_idx_(0), end_idx_(0), size_(0){
            std::memset(data_,'\0',Size*sizeof(Type));
        }

        Type const &
        operator [] ( std::size_t idx )
        {
            idx += begin_idx_;
            if( idx >= Size )
                idx -= Size;
            return data_[idx];
        }

        Type const &
        operator () ( std::size_t idx ) const
        {
            return data_[idx];
        }

        Type&
        add( const Type& element )
        {
            if( begin_idx_ == 0 )
                begin_idx_ = Size;
            --begin_idx_;
            if( begin_idx_ == end_idx_ ){
                if( end_idx_ == 0 )
                    end_idx_ = Size;
                --end_idx_;
            }
            if( size_ < Size )
                ++size_;
            data_[begin_idx_] = element;
            return data_[begin_idx_];
        }

        Type const &
        at( std::size_t idx ) const
        {
            if( idx >= size_ )
                throw std::out_of_range("Index out of range.");
            idx += begin_idx_;
            if( idx >= Size )
                idx -= Size;
            return data_[idx];
        }

        std::size_t
        size() const
        {
            return size_;
        }

//===========================================================================================================
//   #          ###
//    #          #  ##### ###### #####    ##   #####  ####  #####
//     #         #    #   #      #    #  #  #    #   #    # #    #
//      #        #    #   #####  #    # #    #   #   #    # #    #
//     #         #    #   #      #####  ######   #   #    # #####
//    #          #    #   #      #   #  #    #   #   #    # #   #
//   #          ###   #   ###### #    # #    #   #    ####  #    #
//===========================================================================================================
    private:
        class Iterator {
            std::size_t idx_;
            std::size_t trail_;
            std::size_t size_;
            Type* data_ptr_;
        public:
            Iterator(Type* data, std::size_t idx, std::size_t size)
                : idx_(idx), trail_(0), size_(size), data_ptr_(data)
            { }

            Type&
            operator * ()
            {
                return data_ptr_[idx_];
            }

            Iterator&
            operator ++ ()
            {
                ++trail_;
                if( ++idx_ == Size)
                    idx_ -= Size;
                return *this;
            }

            bool
            operator != (const Iterator& it) const
            {
                return trail_!=size_;
            }

        };

//===========================================================================================================
//   #           #####                             ###
//    #         #     #  ####  #    #  ####  #####  #  ##### ###### #####    ##   #####  ####  #####
//     #        #       #    # ##   # #        #    #    #   #      #    #  #  #    #   #    # #    #
//      #       #       #    # # #  #  ####    #    #    #   #####  #    # #    #   #   #    # #    #
//     #        #       #    # #  # #      #   #    #    #   #      #####  ######   #   #    # #####
//    #         #     # #    # #   ## #    #   #    #    #   #      #   #  #    #   #   #    # #   #
//   #           #####   ####  #    #  ####    #   ###   #   ###### #    # #    #   #    ####  #    #
//===========================================================================================================
        class ConstIterator {
            std::size_t idx_;
            std::size_t trail_;
            std::size_t size_;
            const Type* const data_ptr_;
        public:
            ConstIterator(const Type* const data, std::size_t idx, std::size_t size)
                : idx_(idx), trail_(0), size_(size),data_ptr_(data)
            { }

            const Type&
            operator * () const
            {
                return data_ptr_[idx_];
            }

            ConstIterator&
            operator ++ ()
            {
                ++trail_;
                if( ++idx_ == Size)
                    idx_ -= Size;
                return *this;
            }

            bool
            operator != (const ConstIterator& it) const
            {
                return trail_ != size_;
            }

        };

    public:
        Iterator
        begin()
        {
            return { data_, begin_idx_, this->size()};
        }

        Iterator
        end()
        {
            return { data_, this->size(), this->size()};
        }

        ConstIterator
        begin() const
        {
            return { data_, begin_idx_, this->size()};
        }

        ConstIterator
        end() const
        {
            return { data_, this->size(), this->size()};
        }
    };

}; // UL NAMESPACE

#endif // __UL_CONTAINER_CIRCULAR_ARRAY_HPP
