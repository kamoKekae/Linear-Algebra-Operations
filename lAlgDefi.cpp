#include "LAlgebraOps.h"
#include <exception>
#include <algorithm>

void LAlgebra::print(const matrix &Matrix){
    for(auto row : Matrix ){
        std::cout<<"[ ";
        for(auto entry : row){
            std::cout<<entry<<' ';
        }
        std::cout<<']'<<std::endl;
    }
}

void LAlgebra::print(const vector& Vec){
    for(double entry : Vec){
        std::cout<< entry <<' ';    
    }
}

std::pair<int,int> LAlgebra::order(const matrix& Matrix){
    return std::make_pair(Matrix.size(),Matrix[1].size());
}



std::pair<int,int> LAlgebra::order(const LAlgebra::vector Vec){
    if(true)
        return std::make_pair(Vec.size(),1);
    else{
        return std::make_pair(1,Vec.size());
    }
}



std::pair<LAlgebra::matrix,bool> LAlgebra::matrixAddition(const matrix &Lmatrix,const matrix &Rmatrix) {
    auto ord = order(Lmatrix);
    int m  = ord.first;
    int n = ord.second;
    LAlgebra::matrix Result(m,LAlgebra::vector(n,0));

    if( ord != order(Rmatrix)){
        return std::make_pair(Result,false);
    }
    else{
        for(int i =0;i<m;++i){
            for(int j =0;j<n;j++){
                Result[i][j] += Lmatrix[i][j] + Rmatrix[i][j];
            }
        }
    }
    return std::make_pair(Result,true);

}


void LAlgebra::intChangeRow(matrix& __Matrix, int row1, int row2, int n){
    LAlgebra::vector temp;
    //copy contents of row 2;

    for(int j =0;j<n;j++){
        temp.push_back( __Matrix[row2-1][j]);
    }
    
    for(int j =0;j<n;j++){
        __Matrix[row2-1][j] = __Matrix[row1-1][j];

    }

    for(int j = 0;j<n;j++){
        __Matrix[row1-1][j] = temp[j];        
    }

}

void LAlgebra::intChangeCol(matrix& Matrix, int column1, int column2, int m){
    LAlgebra::vector temp;
    //copy contents of row 2;

    for(int j =0;j<m;j++){
        temp.push_back(Matrix[j][column2 -1]);
    }
    
    for(int j =0;j<m;j++){
        Matrix[j][column2 -1] = Matrix[j][column1 -1];

    }

    for(int j = 0;j<m;j++){
        Matrix[j][column1-1] = temp[j];        
    }

}
// #include <algorithm>

void LAlgebra::scalarMult(matrix& Matrix, double k){
        
    for(auto &x : Matrix){
        std::for_each(x.begin(),x.end(),[k](double &a){ a *= k;});
    }
}

// void LAlgebra::scalarMult(vector& Vec,int k){
//     std::for_each(Vec.begin(),Vec.end(),d);
// }

// double MatrixMultiplication(matrix& Lmatrix,matrix& Rmatrix){

// }

double LAlgebra::innerProduct(matrix& LMatrix,matrix& Rmatrix){
    double result = 0;

    if( LAlgebra::order(LMatrix) != LAlgebra::order(Rmatrix) ){

        throw std::logic_error(" Can't compute Inner product for matrices that are not of the same size \n");
    }

    else{
        for(int i =0 ; i < LAlgebra::order(LMatrix).first ; ++i){
            for(int j =0; j< LAlgebra::order(LMatrix).second ; ++j){
                result += LMatrix[i][j] * Rmatrix[i][j]; 
            }
        }
        
        }
    
    return result;
}

double LAlgebra::trace(LAlgebra::matrix &Matrix){
    double trace =0;
    for(int i =0 ; i < Matrix.size() ; i++){
        for( int j =0 ; j< Matrix[i].size() ; i++){
            if ( i == j )
                trace += Matrix[i][j];
        }
    }
    return trace;
}

void LAlgebra::transpose(LAlgebra::matrix &Matrix){
    LAlgebra::matrix transposeMatrix( LAlgebra::order(Matrix).second,LAlgebra::vector( LAlgebra::order(Matrix ).first , 0));

    for( int i =0 ; i < Matrix.size() ; i++){
        for( int j = 0 ; j < Matrix[i].size() ; j++){
            transposeMatrix[j][i] = Matrix[i][j];
        }
    }

    Matrix = transposeMatrix;
}

// TODO GENERAL __delete function for matrices of arbitrary size

LAlgebra::matrix __delete(int row,int column, const LAlgebra::matrix &Matrix ){
    LAlgebra::matrix result; // order n -1 Matrix where n is num rows of Matrix
    for(int i=0 ; i < LAlgebra::order(Matrix).first ; i++){
        if( i == row) continue; // Skip row
        LAlgebra::vector tempRow;
        for ( int j =0; j < LAlgebra::order(Matrix).second ; j++){
            if( j != column){
                tempRow.push_back(Matrix[i][j]);
            }
        }
        result.push_back(tempRow);
        tempRow.resize(0);
    }

    return result;
}

double LAlgebra::determinant(const LAlgebra::matrix &Matrix){
    // Check if the matrix is square
    
    if( LAlgebra::order(Matrix).first != LAlgebra::order(Matrix).second ){
        std::logic_error error(" Cannot Compute 'Determinant' for Non-Square Matrices");
        throw error;
    }
    else{
        if( LAlgebra::order(Matrix) == std::make_pair(2,2) ){
            return Matrix[0][0] * Matrix[1][1] - Matrix[0][1] * Matrix[1][0];
        }
        else{
            double __determinant = 0;

            for ( int j = 0 ; j < LAlgebra::order(Matrix).second ; j++ ){
                int i =1;

                LAlgebra::matrix nMinusOneMatrix = __delete(i,j,Matrix);
                __determinant += std::pow(-1,(i + 1 ) + (j +1) ) * Matrix[i][j] * determinant( nMinusOneMatrix);
            }
            return __determinant;      
            }
        }   
}

LAlgebra::matrix LAlgebra::MatrixMultiply(const LAlgebra::matrix& Lmatrix , const LAlgebra::matrix& Rmatrix){
    LAlgebra::matrix product(LAlgebra::order(Lmatrix).first , LAlgebra::vector(LAlgebra::order(Lmatrix).second,0) );

    if( LAlgebra::order(Lmatrix).second != LAlgebra::order(Rmatrix).first ){
        throw std::logic_error("Matrix Multiplication for inconsistent dimensions undefined ");
        // throw error;
    }
    for ( int i =0; i < LAlgebra::order(Lmatrix).first ; ++i ){
        for (int j =0; j < LAlgebra::order(Rmatrix).second ; ++j ){
            for (int k =0; k < LAlgebra::order(Rmatrix).first ; k ++ ){
                product[i][j] += Lmatrix[i][k] * Rmatrix[k][j];
            }
        }
    }
    return product;
}

LAlgebra::matrix pow( LAlgebra::matrix &Matrix,int pow){

    if( pow %2 ==  0){
        
    }
}