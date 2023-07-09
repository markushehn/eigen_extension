/**
 * @file main.cpp
 * @brief main source file
 * @author Markus Hehn
 * @date 09.07.2023
 * 
 * This code executes the test of the library functions.
 */


#include <iostream>
#include <complex>
#include <Eigen/Dense>

#include "eigen_random.hpp"
#include "eigen_csv.hpp"
#include "eigen_pinv.hpp"


using namespace std::literals;


void eigen_random_test(void)
{
    std::cout << "Eigen random test" << std::endl;
    
    Eigen::MatrixXd A(5,7);
    A = EigenRandom::randn(5,7);
    std::cout << A << std::endl;
    
    Eigen::Vector3d v;
    v = EigenRandom::randn(3,1);
    std::cout << v << std::endl;
    
    Eigen::MatrixXd B(10,10);
    B = EigenRandom::rand(10);
    std::cout << B << std::endl;
}


void eigen_csv_test(void)
{
    std::cout << "Eigen CSV test" << std::endl;
    
    Eigen::MatrixXd A = EigenCSV::csv_read("./test_read.csv");
    
    Eigen::Vector3d B;
    B << 1.1,2.0,3.0;
    EigenCSV::csv_write("./test_write.csv" , B);
    EigenCSV::csv_write("./test_write2.csv" , B);
    
    std::cout << A << std::endl;
}


void eigen_pinv_test(void)
{
    std::cout << "Eigen pinv test" << std::endl;
    
    Eigen::MatrixXd A(5,4);
    A << 1.0 , 0.0 , 0.0 , 0.0 ,
         0.0 , 1.0 , 0.0 , 0.0 ,
         0.0 , 0.0 , 0.0 , 0.0 ,
         0.0 , 0.0 , 0.0 , 0.0 ,
         0.0 , 0.0 , 0.0 , 0.0 ;
    
    std::cout << "A = " << std::endl << A << std::endl;
    
    Eigen::MatrixXd Apinv = EigenPinv::pinv<Eigen::MatrixXd>(A);
    std::cout << "Apinv =" << std::endl << Apinv << std::endl;
    std::cout << "Apinv test:" << std::endl << A * Apinv << std::endl;
    std::cout << "Apinv test:" << std::endl << Apinv * A << std::endl;
    
    
    Eigen::MatrixXcd Ac(5,4);
    Ac << 1.0 + 1.0i , 0.0 , 0.0 , 0.0 ,
          0.0 , 1.0 , 0.0 , 0.0 ,
          0.0 , 0.0 , 0.0 , 0.0 ,
          0.0 , 0.0 , 0.0 , 0.0 ,
          0.0 , 0.0 , 0.0 , 0.0 ;
    
    std::cout << "Ac = " << std::endl << Ac << std::endl;
    
    Eigen::MatrixXcd Acpinv = EigenPinv::pinv<Eigen::MatrixXcd>(Ac);
    std::cout << "Acpinv =" << std::endl << Acpinv << std::endl;
    std::cout << "Acpinv test:" << std::endl << Ac * Acpinv << std::endl;
    std::cout << "Acpinv test:" << std::endl << Acpinv * Ac << std::endl;
}


int main(void)
{
    eigen_random_test();
    eigen_csv_test();
    eigen_pinv_test();
    return 0;
}
