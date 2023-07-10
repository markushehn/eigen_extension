/**
 * @file eigen_csv.cpp
 * @brief Eigen CSV source file
 * @author Markus Hehn
 * @date 10.07.2023
 */


#include <Eigen/Dense>
#include <vector>
#include <fstream>
#include <stdexcept>


namespace EigenCSV
{
    /**
     * Code inspiration from https://stackoverflow.com/questions/34247057/how-to-read-csv-file-and-assign-to-eigen-matrix (the code is NOT copied)
     */
    Eigen::MatrixXd csv_read(const std::string csv_path)
    {
        std::ifstream csv_file(csv_path);
        if(csv_file.good() == false)
            throw std::runtime_error("Eigen CSV error: Unable to read.");
        std::vector<double> csv_values;
        unsigned int csv_line_num = 0;
        std::string csv_line;
        while(std::getline(csv_file, csv_line))
        {
            std::stringstream csvLineStream(csv_line);
            std::string csv_cell_value;
            while(std::getline(csvLineStream, csv_cell_value, ','))
            {
                csv_values.push_back(std::stod(csv_cell_value));
            }
            csv_line_num++;
        }
        return Eigen::Map<const Eigen::Matrix<Eigen::MatrixXd::Scalar, Eigen::MatrixXd::RowsAtCompileTime, Eigen::MatrixXd::ColsAtCompileTime, Eigen::RowMajor>>(csv_values.data(), csv_line_num, csv_values.size() / csv_line_num);
    }
    
    /**
     * Code inspiration from https://stackoverflow.com/questions/18400596/how-can-a-eigen-matrix-be-written-to-file-in-csv-format/23566993#23566993 (the code is NOT copied)
     */
    void csv_write(const std::string csv_path , Eigen::MatrixXd matrix)
    {
        const static Eigen::IOFormat csv_format(Eigen::StreamPrecision, Eigen::DontAlignCols, ",", "\n");        // define CSV file format, see https://eigen.tuxfamily.org/dox/structEigen_1_1IOFormat.html
        std::ofstream csv_file(csv_path);
        if(csv_file.good() == false)
            throw std::runtime_error("Eigen CSV error: Unable to write.");
        csv_file << matrix.format(csv_format);
        // csv_file is closed by the destructor
    }
}
