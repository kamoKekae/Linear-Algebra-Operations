#include <iostream>
#include <vector>
#include "LAlgebraOps.h"

int main(){
    LAlgebra::matrix LMatrix = {
                                {-1,4},
                                {2,3}
                                };                           
    
    LAlgebra::matrix RMatrix = {
                                {9,-3}
                                
                                };  

    LAlgebra::print(LAlgebra::MatrixMultiply(LMatrix,RMatrix));
    std::cout<<"\n";
    
    return 0;
}