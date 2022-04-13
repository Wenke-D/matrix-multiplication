// Including 'hpx/hpx_main.hpp' instead of the usual 'hpx/hpx_init.hpp' enables
// to use the plain C-main below as the direct main HPX entry point.

#include <cassert>
#include <iostream>
#include <stdexcept>
#include <vector>

#include <hpx/hpx_main.hpp>
#include <hpx/iostream.hpp>
#include <hpx/algorithm.hpp>
#include <hpx/numeric.hpp>
#include <hpx/async_combinators/split_future.hpp>

#include "output.hpp"



// matrix[i][j], i row index, j col index
using matrix = std::vector<std::vector<int>>;



int inner_product(std::vector<int> v1, std::vector<int> v2){
    return hpx::transform_reduce(
        hpx::execution::seq,
        v1.begin(), v1.end(), 
        v2.begin(),
        0,
        std::plus<int>(), 
        std::multiplies<int>()
    );
}



std::vector<int> col_of_matrix(matrix& m, int col){
    std::vector<int> res;
    for(auto& row: m){
        res.push_back(row[col]);
    }
    return res;
}


/**
 * @brief Matrix multiplication
 * 
 * @param m1 the first operand
 * @param m2 the second operand
 * @return matrix product
 */
matrix operator*(matrix& m1, matrix& m2){
    // if contain a empty matrix, return empty matrix
    if(m1.size() == 0 || m2.size() == 0) return matrix{};

    // check dimension of 2 operands
    if(m1[0].size() != m2.size()){
        throw std::invalid_argument("size error");
    }

    // result matrix dimension
    int height = m1.size(), width = m2[0].size();

    // init the result matrix
    matrix res(height, std::vector<int>(width, 0));
    // we parallelly and asynchrously do multiplication
    std::vector<hpx::future<void>> futures;
    // multiplication is done by inner product of row and col
    for (size_t i = 0; i < height; i++)
    {
        // row of first matrix
        auto a = m1[i];
        for (size_t j = 0; j < width; j++)
        {

            hpx::future<void> f = hpx::async([&m2,i, j, &res, a](){
                auto b = col_of_matrix(m2, j);
                res[i][j] = inner_product(a, b);
            });

            futures.push_back(f);
        }
    }

    // synchrounize all futures
    for(auto& f: futures){
        f.wait();
    }

    return res;
}


int main() {
    
    matrix m1{
        {1, 2},
        {3, 4}
    };

    matrix m2{
        {4, 5},
        {6, 7}
    };

    matrix I_2{
        {1, 1},
        {1, 1}
    };

    std::vector<int> v1 = {1, 2, 3};
    std::vector<int> v2 = {1, 1, 1};

    std::cout << inner_product(v1, v2) << std::endl;
    matrix m = m1 * m2;

}