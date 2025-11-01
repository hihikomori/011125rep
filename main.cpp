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
      std::cerr << e.what();
      rm(mtx, i);
      throw;
    }
  }
  return mtx;
}

void output(const int *const *mtx);

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
    return 2;
  }
  output(mtx);
  rm(mtx, rows);
}
