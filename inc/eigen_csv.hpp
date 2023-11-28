/**
 * @file eigen_csv.hpp
 * @brief Eigen CSV header file
 * @author Markus Hehn
 * @date 28.11.2023
 * 
 * The function csv_read reads the data of a CSV file and returns the data as a Eigen matrix. The function csv_write writes a Eigen matrix to a CSV file.
 */


#ifndef EIGEN_CSV_HPP
#define EIGEN_CSV_HPP


#include <Eigen/Dense>


namespace EigenCSV
{
    Eigen::MatrixXd csv_read(const std::string csv_path);
    void csv_write(const std::string csv_path , Eigen::MatrixXd matrix);
}


#endif
