#define CATCH_CONFIG_MAIN // CATCH should provide main function
#include "catch.hpp"
#include "../LAlgebraOps.h"
#include <vector>

TEST_CASE(" TESTING TRANSPOSE "){
    LAlgebra::matrix Matrix = {
                                {1,4},
                                {6,7},
                                {1,4}
                                };
    REQUIRE(LAlgebra::order(Matrix) == std::make_pair(3,2) );
    // Perfom Transpose 
    LAlgebra::transpose(Matrix);
    REQUIRE( LAlgebra::order(Matrix) == std::make_pair(2,3) );
    REQUIRE( Matrix == LAlgebra::matrix({{1,6,1},
                                        {4,7,4}
                                        }));  
}

TEST_CASE("Testing Power Function"){
    LAlgebra::matrix matrixA = {
                            {3,7,0},
                            {,0,6,2},
                            {5,8,7}
                            };
   

    REQUIRE (LAlgebra::pow(matrixA,4) == LAlgebra::matrix({
                                                            {1411,5789,2674},
                                                            {1910,6948,3182},
                                                            {5090,19413,8539}
                                                            }));

    REQUIRE (LAlgebra::pow(matrixA,3) == LAlgebra::matrix({
                                                            {97,553,224},
                                                            {160,590,286},
                                                            {475,1704,733}
                                                            }));
}
