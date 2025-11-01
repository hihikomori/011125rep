#include <iostream>

// using ull = unsigned long long;

int **makeMtx(int rows, int cols);

void output(const int *const *mtx);

void rm(int **mtx, int rows) {
  for (size_t i = 0; i < rows; i++) {
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
  mtx = makeMtx(rows, cols);
  output(mtx);
  rm(mtx, rows);
}
