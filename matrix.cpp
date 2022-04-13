#include "matrix.hpp"

template <typename T>
std::vector<T> Matrix<T>::operator[](size_t i) {
    if (i >= height)
        throw std::invalid_argument("Line too big");
    auto &begin = this->data.begin() + i * this->width;
    auto &end = begin + this->width;
    std::vector<T> line(begin, end);
    return line;
}

template <typename T> void Matrix<T>::set(size_t i, size_t j, T v) {
    this->data[(i - 1) * width + j] = v;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const Matrix<T> &m) {
    for (size_t i = 0; i < m.data.size(); i++) {
        os << m.data[i];
        // if ((i + 1) % m.width == 0) {
        //     os << string("\n");
        // } else {
        //     os << string(" ");
        // }
    }
    return os;
}