#include <cstddef>
#include <vector>
class matrix {
  size_t n_;
  double **array_;

  void multiply(double num) {
    for (int i = 0; i < n_; i++) {
      for (int j = 0; j < n_; j++) {
        array_[i][j] *= num;
      }
    }
  }

  friend matrix &operator*(double left, matrix &right);
  friend matrix &operator*(matrix &left, double right);

public:
  matrix(int n) : n_(n) {
    array_ = new double *[n_];
    for (int i = 0; i < n_; i++) {
      array_[i] = new double[n_];
    }
  }

  matrix(const matrix &other) : matrix(other.n_) {
    for (int i = 0; i < n_; i++) {
      for (int j = 0; j < n_; j++) {
        array_[i][j] = other.array_[i][j];
      }
    }
  }

  matrix(matrix &&other) : n_(other.n_), array_(other.array_) {
    other.array_ = nullptr;
  }

  matrix(std::vector<double> diagonal) : matrix(diagonal.size()) {
    for (int i = 0; i < n_; i++) {
      for (int j = 0; j < n_; j++) {
        if (i == j) {
          array_[i][j] = diagonal.at(i);
        } else {
          array_[i][j] = 0;
        }
      }
    }
  }

  explicit operator double() {
    double summ = 0;
    for (int i = 0; i < n_; i++) {
      for (int j = 0; j < n_; j++) {
        summ += array_[i][j];
      }
    }
    return summ;
  }

  matrix operator+(const matrix other) const{
    matrix result = matrix(n_);
    for (int i = 0; i < n_; i++) {
      for (int j = 0; j < n_; j++) {
        result.array_[i][j] = array_[i][j] + other.array_[i][j];
      }
    }
    return result;
  }

  matrix &operator+=(const matrix other) {
    for (int i = 0; i < n_; i++) {
      for (int j = 0; j < n_; j++) {
        array_[i][j] += other.array_[i][j];
      }
    }
    return *this;
  }

  matrix operator*(const matrix other) {
    matrix result = matrix(n_);
    for (int i = 0; i < n_; i++) {
      for (int j = 0; j < n_; j++) {
        result.array_[i][j] = 0;
        for (int k = 0; k < n_; k++) {
          result.array_[i][j] += array_[i][k] * other.array_[k][j];
        }
      }
    }
    return result;
  }

  matrix &operator*=(const matrix other) {
    matrix result(n_);
    for (int i = 0; i < n_; i++) {
      for (int j = 0; j < n_; j++) {
        result.array_[i][j] = 0;
        for (int k = 0; k < n_; k++) {
          result.array_[i][j] += array_[i][k] * other.array_[k][j];
        }
      }
    }
    std::swap(array_, result.array_);
    return *this;
  }

  matrix &operator*=(const double lambda) {
    multiply(lambda);
    return *this;
  }

  matrix &operator=(matrix other) {
    n_ = other.n_;
    std::swap(array_, other.array_);
    return *this;
  }

  bool operator==(matrix &other) {
    for (int i = 0; i < n_; i++) {
      for (int j = 0; j < n_; j++) {
        if (array_[i][j] != other.array_[i][j]) {
          return false;
        }
      }
    }
    return true;
  }

  bool operator!=(matrix &other) { return !(*this == other); }

  ~matrix() {
    if (array_) {
      for (int i = 0; i < n_; i++) {
        delete[] array_[i];
      }
      delete[] array_;
    }
  }

  double *operator[](size_t index) { return array_[index]; }
};

matrix &operator*(double left, matrix &right) {
  right.multiply(left);
  return right;
}
matrix &operator*(matrix &left, double right) {
  left.multiply(right);
  return left;
}
