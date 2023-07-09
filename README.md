# eigen_extension library

This library extends the Eigen-library with additional functionality:

- CSV read and write
- Pseudoinverse calculation based on the singular value decomposition (SVD)
- Generation of random matrices

Goal of this library is a simple usage and a similar syntax to Matlab. See the header files in the folder ```./inc``` for more information and the file ```./src/main.c``` for usage details.


# Respository structure

```.kateproject``` includes the project definition for the editor "Kate". ```./src``` include the source files and ```./inc``` the header files. ```./src/main.c``` executes the library test.
