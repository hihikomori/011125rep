#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <new>

void rm(int **mtx, size_t rows);

int **makeMtx(const size_t * lns, size_t rows) {
  int **mtx = new int *[rows];
  for (size_t i = 0; i < rows; ++i) {
    try {
      mtx[i] = new int[lns[i]];
    } catch (std::bad_alloc &e) {
      rm(mtx, i);
      throw;
    }
  }
  return mtx;
}

void input(int **mtx, const size_t * lns, int rows, const int * t, size_t n) {
  size_t cnt = 0;
  for (size_t i = 0; i < rows; ++i) {
    for (size_t j = 0; j < lns[i]; ++j) {
      mtx[i][j] = t[cnt];
			++cnt;
      if(cnt >= n){
        break;
      }
    }
  }
}

void output(int ** mtx, size_t rows, const size_t * lns) {
  for(int i = 0; i < rows; ++i){
    for (size_t j = 0; j < lns[i]; ++j) {
      std::cout << mtx[i][j] << ' ';
    }
	  std::cout << '\n';
	}
}

void rm(int **mtx, size_t rows) {
  for (size_t i = 0; i < rows; ++i) {
    delete[] mtx[i];
  }
  delete[] mtx;
}

int ** convert(const int * t, size_t n, const size_t * lns, size_t rows){
  int ** mtx = nullptr;
  try{
    mtx = makeMtx(lns, rows);
  }catch(std::bad_alloc){
    throw;
  }
  input(mtx, lns, rows, t, n);
	output(mtx, rows, lns);
  return mtx;
}

int main() {
  int exit_code = 0;
  int ** mtx = nullptr;
  size_t n = 12;
  int * t = new int[n]{5,5,5,5,6,6,7,7,7,7,7,8};
  size_t rows = 4;
  size_t * lns = new size_t[rows]{4,2,5,1};
  try{
    mtx = convert(t, n, lns, rows);
  }catch(std::bad_alloc &e){
    exit_code = 2;
  }
  catch(...){
    exit_code = 3;
  }
  delete[] t;
  delete[] lns;
  if (mtx) {rm(mtx, rows);}
  return exit_code;
}
