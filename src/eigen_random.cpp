/**
 * @file eigen_random.cpp
 * @brief Eigen random source file
 * @author Markus Hehn
 * @date 24.07.2022
 */


#include <random>
#include <Eigen/Dense>
#include "eigen_random.hpp"


namespace EigenRandom
{
    std::random_device random_device{};
    std::mt19937 random_generator{random_device()};
    std::normal_distribution<double> standard_distribution{0.0,1.0};                // standard distribution with zero mean and standard deviation of one
    std::uniform_real_distribution<double> uniform_distribution{0.0,1.0};           // uniform distribution with the interval [0,1]
    
    Eigen::MatrixXd rand(int row_num, int col_num)
    {
        return Eigen::MatrixXd::NullaryExpr(row_num, col_num, [&](){return uniform_distribution(random_generator);});
    }
    
    Eigen::MatrixXd rand(int row_num)
    {
        return Eigen::MatrixXd::NullaryExpr(row_num, row_num, [&](){return uniform_distribution(random_generator);});
    }
    
    Eigen::MatrixXd randn(int row_num, int col_num)
    {
        return Eigen::MatrixXd::NullaryExpr(row_num, col_num, [&](){return standard_distribution(random_generator);});
    }
    
    Eigen::MatrixXd randn(int row_num)
    {
        return Eigen::MatrixXd::NullaryExpr(row_num, row_num, [&](){return standard_distribution(random_generator);});
    }
}
