#include <stdexcept>
#include <vector>
#include <string>

template <typename T> class Matrix {
  private:
    std::vector<T> data;


  public:
    size_t width;
    size_t height;

    /**
     * @brief Construct a new Matrix object by declearing its size and default value
     * 
     * @param width width of the matrix
     * @param height height of the matrix
     * @param default_value default value of all elements
     */
    Matrix(size_t width, size_t height, T default_value)
        : width(width), height(height) {
        data.resize(width * height);
    }

    /**
     * @brief Get a row of the matrix
     *
     * @param i row index, begin from 0
     * @return std::vector<T>
     */
    std::vector<T> operator[](size_t i);

    /**
     * @brief Get a the column j
     * 
     * @param j index of a col
     * @return std::vector<T> 
     */
    std::vector<T> col(size_t j);

    void set(size_t i, size_t j, T v);

    template <typename U>
    friend std::ostream &operator<<(std::ostream &os, const Matrix<U> &m);
};


template <typename T>
std::vector<T> Matrix<T>::operator[](size_t i) {
    if (i >= height)
        throw std::invalid_argument("Line too big");
        
    auto begin = this->data.begin() + i * this->width;
    auto end = begin + this->width;
    std::vector<T> line(begin, end);
    return line;
}

template <typename T>
std::vector<T> Matrix<T>::col(size_t j) {
    if (j >= width)
        throw std::invalid_argument("col too big");
        
    std::vector<T> col;
    for (size_t i = j; i < this->data.size(); i+=this->width)
    {
        col.push_back(this->data[i]);
    }
    
    return col;
}

/**
 * @brief Set a value in location (i, j) of the matrix
 * 
 * @tparam T value type of martix
 * @param i row index
 * @param j col index
 * @param v value
 */
template <typename T> void Matrix<T>::set(size_t i, size_t j, T v) {
    if(i >= this->height || j >= this->width){
        throw std::invalid_argument("Oversize");
    }

    this->data[i * width + j] = v;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const Matrix<T> &m) {
    os << "Matrix" << std::endl;
    for (size_t i = 0; i < m.data.size(); i++) {
        os << m.data[i];
        if ((i + 1) % m.width == 0) {
            os << std::string("\n");
        } else {
            os << std::string(" ");
        }
    }
    os << "----" << std::endl;

    return os;
}
