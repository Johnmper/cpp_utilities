#ifndef __UL_FILTER_KALMAN_HPP
#define __UL_FILTER_KALMAN_HPP

#include<iostream>
#include<Eigen/Eigen>

namespace ul{

    template<typename T, unsigned int Nx, unsigned int Nz>
    struct Kalman{
    static_assert(std::is_floating_point<T>::value,"Must by type float or double");
    static_assert(Nx >= Nz, "Nx must be >= Nz.");

        /// Transition State Matrix
        Eigen::Matrix<T,Nx,Nx>  A;
        /// Observation Matrix
        Eigen::Matrix<T,Nz,Nx>  H;
        /// Process Noise Covariance
        Eigen::Matrix<T,Nx,Nx>  Q;
        /// Measurement Noise Covariance
        Eigen::Matrix<T,Nz,Nz>  R;

        /// A Priori Estimate of the Error Covariance
        Eigen::Matrix<T,Nx,Nx>  P;
        /// Calculated Kalman Gain
        Eigen::Matrix<T,Nx,Nz>  K;

        /// Internal Process State
        Eigen::Matrix<T,Nx,1>   x;

        Kalman() {
            A.setIdentity();
            H.setZero();
            H.leftCols(Nz) = Eigen::Matrix<T,Nz,Nz>::Identity();
            Q.setIdentity();
            R.setIdentity();
            P.setIdentity();
            x.setZero();
        }
        ~Kalman(){}

        void
        predict(Eigen::Matrix<T,Nx,1> u = Eigen::Matrix<T,Nx,1>::Zero()){
            // Predict Next State
            x = A*x + u;
            // Predict Next State Covariance
            P = A*P*A.transpose() + Q;
        }

        void
        update(Eigen::Matrix<T,Nz,1> z)
        {
            // Calculate Kalman Gain
            K = P*H.transpose()*(H*P*H.transpose() + R).inverse();
            // Correct Next State with the Observation
            x = x + K*(z-H*x);
            // Update the State Covariance with the Observation
            P = P - K*H*P;
        }

        Eigen::Matrix<T,Nz,1>
        state()
        {
            return H*x;
        }

        void
        showInfo()
        {
            // Ouput equal to Matlab Matrices
            static Eigen::IOFormat matlab_fmt(Eigen::StreamPrecision, 0, ", ", ";\n", "", "", "[", "]");
            std::cout << "x:\n" << x.format(matlab_fmt) << std::endl;
            std::cout << "A:\n" << A.format(matlab_fmt) << std::endl;
            std::cout << "H:\n" << H.format(matlab_fmt) << std::endl;
            std::cout << "Q:\n" << Q.format(matlab_fmt) << std::endl;
            std::cout << "R:\n" << R.format(matlab_fmt) << std::endl;
            std::cout << "P:\n" << P.format(matlab_fmt) << std::endl;
            std::cout << "K:\n" << K.format(matlab_fmt) << std::endl;
        }
    };


};  // UL NAMESPACE

#endif // __UL_FILTER_KALMAN_HPP
