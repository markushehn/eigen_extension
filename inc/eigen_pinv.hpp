/**
 * @file eigen_pinv.hpp
 * @brief Eigen Pinv header file
 * @author Markus Hehn
 * @date 28.11.2023
 * 
 * This library extends the Eigen library with the functionality of calculation of the pseudo inverse based on the singular value decomposition (SVD).
 * The syntax is similar to the syntax of Matlab.
 */


#ifndef EIGEN_PINV_HPP
#define EIGEN_PINV_HPP


#include <Eigen/Dense>


namespace EigenPinv
{
    /**
     * Code copied from https://eigen.tuxfamily.org/index.php?title=FAQ#Is_there_a_method_to_compute_the_.28Moore-Penrose.29_pseudo_inverse_.3F
     */
    template<typename matrix_type>
    matrix_type pinv(const matrix_type A)
    {
        double epsilon = std::numeric_limits<double>::epsilon();
        Eigen::JacobiSVD<matrix_type> svd(A, Eigen::ComputeThinU | Eigen::ComputeThinV);                        // "Thin" calculates U and V like that zero lines or columns must not be inserted in Sigma
        svd.setThreshold(epsilon * std::max(A.cols(), A.rows()));                                               // sets threshold in rank calculation
        Eigen::Index rank = svd.rank();
        // the calculation formula eliminates zero lines or columns in U and V and also in Sigma to minimize the computational load
        return svd.matrixV().leftCols(rank) * svd.singularValues().head(rank).asDiagonal().inverse() * svd.matrixU().leftCols(rank).adjoint();
    }
}


#endif
