#include <stdexcept>
#include <vector>

template <typename T> class Matrix {
  private:
    std::vector<T> data;
    size_t width;
    size_t height;

  public:
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

    void set(size_t i, size_t j, T v);
    
    template<typename U>
    friend std::ostream &operator<<(std::ostream &os, const Matrix<U> &m);
};