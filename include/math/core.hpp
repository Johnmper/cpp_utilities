#ifndef __UL_MATH_CORE_HPP
#define __UL_MATH_CORE_HPP

#include<Eigen/Eigen>

namespace ul{

const static double pi = 3.14159265358979323846;    // double precision only has 15 decimal places!

namespace math{
    template<typename T>
    Eigen::Matrix<T,3,3> xrot(T roll){
    static_assert(std::is_floating_point<T>::value,"Must by type float or double");
        Eigen::Matrix<T,3,3> rot;
        rot << 1, 0, 0, 0, cos(roll), sin(roll), 0, -sin(roll), cos(roll);
        return rot;
    }

    template<typename T>
    Eigen::Matrix<T,3,3> yrot(T pitch){
    static_assert(std::is_floating_point<T>::value,"Must by type float or double");
        Eigen::Matrix<T,3,3> rot;
        rot << cos(pitch), 0, -sin(pitch), 0, 1, 0, sin(pitch), 0, cos(pitch);
        return rot;
    }

    template<typename T>
    Eigen::Matrix<T,3,3> zrot(T yaw){
    static_assert(std::is_floating_point<T>::value,"Must by type float or double");
        Eigen::Matrix<T,3,3> rot;
        rot << cos(yaw), sin(yaw), 0, -sin(yaw), cos(yaw), 0, 0, 0, 1;
        return rot;
    }

    template<typename T>
    Eigen::Matrix<T,3,3> eulerXYZ(T roll, T pitch, T yaw){
    static_assert(std::is_floating_point<T>::value,"Must by type float or double");
        return xrot<T>(roll)*yrot<T>(pitch)*zrot<T>(yaw);
    }

};  // MATH NAMESPACE

};  // UL NAMESPACE

#endif // __UL_MATH_CORE_HPP
