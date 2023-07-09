/**
 * @file eigen_random.hpp
 * @brief Eigen random header file
 * @author Markus Hehn
 * @date 24.07.2022
 * 
 * This library extends the Eigen library with the generation of random matrices.
 * The random numbers are distributed according to certain probability density functions.
 * Code is based on the example from: http://eigen.tuxfamily.org/dox/classEigen_1_1DenseBase.html
 * The syntax of the functions is similar to the syntax of Matlab.
 */


#ifndef EIGEN_RANDOM_HPP
#define EIGEN_RANDOM_HPP


namespace EigenRandom
{
    Eigen::MatrixXd rand(int row_num, int col_num);
    Eigen::MatrixXd rand(int row_num);
    Eigen::MatrixXd randn(int row_num, int col_num);
    Eigen::MatrixXd randn(int row_num);
}


#endif
