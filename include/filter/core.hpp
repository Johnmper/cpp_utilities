#ifndef __UL_FILTER_CORE_HPP
#define __UL_FILTER_CORE_HPP

#include<iostream>
#include<Eigen/Eigen>


namespace ul{


    template<typename T>
    struct LowPass{

        const T alpha;  /// Alpha represents the intensity of the LowPass Filter, higher more smoothness
        T value;        /// Last smoothed result

        /// Default constructor, util for filter arrays
        LowPass() :  alpha(1), value(0){
            static_assert(std::is_floating_point<T>::value, "Must by type float or double");
        }

        /// Complete Constructor
        LowPass(const T _alpha, const T _value) : alpha(_alpha), value(_value){
            static_assert(std::is_floating_point<T>::value, "Must by type float or double");
            static_assert( _alpha < 0 || 1 < _alpha, "Alpha must be between value [0,1]");
        }

        /// Filtering operation
        T filter(const T& _value){
            value = alpha*value + (1-alpha)*_value;
            return value;
        }

        /// Sets internal value, returns the previous value
        T set(const T& _value){
            T previous;
            value = _value;
            return previous;
        }
    };


};  // UL NAMESPACE


#endif // __UL_FILTER_CORE_HPP
