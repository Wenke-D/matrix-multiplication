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

#include "matrix.hpp"
#include "output.hpp"

using namespace std;

int main() {

    Matrix<int> m1{2, 2, 2};

    Matrix<int> I_2{2, 2, 1};

    cout << I_2 << endl;

    cout << I_2[0] << endl;
}