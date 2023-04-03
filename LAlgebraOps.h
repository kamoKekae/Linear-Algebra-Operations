#ifndef LINEAR_ALGEBRA_OPS_H
#define LINEAR_ALGEBRA_OPS_H
#include <iostream>
#include <math.h>
#include <vector>

namespace LAlgebra{
    /**
     *Header file that specifies basic functions for Linear Algebra
    *
    * File under iterative refinement
    * Most functions will be taking an order(m,n) matrix by reference
    * */

    typedef std::vector<std::vector<double>>  matrix;
    typedef std::vector<double> vector;

    /**utility functions for printing matrix to console
     * @param: created matrix taken as reference 
     * 
     * void
     **/

    void print(const matrix& Matrix);
    void print(const vector& Vec);

    double determinant(const matrix & Matrix);

    /**
     *@return: 2 t-tuple stating order
    *@param: matrix 
    * overload : order(*@param : vector)
    **/

    std::pair<int,int> order(const matrix& Matrix );
    std::pair<int,int> order(vector Vec);

    /**Matrix Addition
     *@params  : Two Matrices to be added
    *return : bool 
    * */

    std::pair<matrix,bool> matrixAddition(const matrix &Lmatrix,const matrix &Rmatrix);
// std::pair<matrix,bool> matrixAddition(lAlgebra::matrix& Lmatrix, lAlgebra::matrix &Rmatrix,char &mode);

    /**
     * 1)Elementary row and column interchanges
     * 2)Scalar Multiplication for vectors and Matrices
     * Multiplication by a factor k
     * */

    void intChangeRow(matrix& matrix, int row1, int row2, int n);
    void intChangeCol(matrix& matrix, int col1, int col2, int m);


    void scalarMult(matrix& matrix,double k);
    void scalarMult(vector& Vec,int k);

    /**
     * 1) Matrix Multiplication
     * 2) Inner Product For Vectors and matrices
     * 3) Trace of  a matrix
     * */

    matrix MatrixMultiply(const matrix& Lmatrix,const matrix& Rmatrix);


    LAlgebra::matrix pow(const LAlgebra::matrix &Matrix);

    double innerProduct(vector& vec1,vector& vec2);
    double innerProduct(matrix& LMatrix,matrix& Rmatrix);

    double trace(LAlgebra::matrix & Matrix);
    void transpose( matrix &Matrix);
}

#endif