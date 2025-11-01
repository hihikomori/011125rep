#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <new>

void rm(int **mtx, int rows);

int **makeMtx(int rows, int cols) {
  int **mtx = new int *[rows];
  for (size_t i = 0; i < rows; ++i) {
    try {
      mtx[i] = new int[cols];
    } catch (std::bad_alloc &e) {
      rm(mtx, i);
      throw;
    }
  }
  return mtx;
}

void input(int **mtx, int rows, int cols) {
  for (size_t i = 0; i < rows; ++i) {
    for (size_t j = 0; j < cols; ++j) {
      std::cin >> mtx[i][j];
    }
  }
}

void output(const int *const *mtx, int rows, int cols) {
  for (size_t i = 0; i < rows; ++i) {
    for (size_t j = 0; j < cols; ++j) {
      std::cout << mtx[i][j];
    }
    std::cout << std::endl;
  }
}

void rm(int **mtx, int rows) {
  for (size_t i = 0; i < rows; ++i) {
    delete[] mtx[i];
  }
  delete[] mtx;
}

int main() {
  int rows = 0, cols = 0;
  std::cin >> rows >> cols;
  if ((std::cin.fail())) {
    return 1;
  }
  int **mtx = nullptr;
  try {
    mtx = makeMtx(rows, cols);
  } catch (const std::bad_alloc &e) {
    std::cerr << e.what();
    return 2;
  }

  input(mtx, rows, cols);
  if (std::cin.bad()) {
    std::cerr << "Error, bad input";
    rm(mtx, rows);
    return 1;
  }
  output(mtx, rows, cols);
  rm(mtx, rows);
}
