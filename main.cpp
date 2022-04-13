// Including 'hpx/hpx_main.hpp' instead of the usual 'hpx/hpx_init.hpp' enables
// to use the plain C-main below as the direct main HPX entry point.

#include <cassert>
#include <iostream>
#include <stdexcept>
#include <vector>

#include <hpx/algorithm.hpp>
#include <hpx/hpx_main.hpp>
#include <hpx/iostream.hpp>
#include <hpx/numeric.hpp>

#include "include/matrix.hpp"
#include "include/output.hpp"

using namespace std;

/**
 * @brief inner product of 2 vectors, assuming they have the same size.
 *
 * @param v1
 * @param v2
 * @return int
 */
int operator*(vector<int> v1, vector<int> v2) {
    return hpx::transform_reduce(v1.begin(), v1.end(), v2.begin(), 0,
                                 std::plus<int>(), std::multiplies<int>());
}

Matrix<int> operator*(Matrix<int> m1, Matrix<int> m2) {

    size_t height = m1.height, width = m2.width;

    Matrix<int> res{height, width, 0};

    for (size_t i = 0; i < height; i++)
    {
        for (size_t j = 0; j < width; j++)
        {   
            int value = m1[i] * m2.col(j);
            res.set(i, j, value);
        }
        
    }
    return res;
}

int main() {

    Matrix<int> m1{2, 2, 2};

    Matrix<int> I_2{2, 2, 1};

    cout << m1;
    m1.set(0, 0, 5);
    cout << m1;
    m1.set(1, 1, 10);
    cout << m1;

    cout << m1[0] << endl;
    cout << m1[1] << endl;
    cout << m1.col(0) << endl;
    cout << m1.col(1) << endl;

    cout << m1[0] * m1[0] << endl;

    cout << m1 * m1;
}