#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <new>

void rm(int **mtx, size_t rows);

int **makeMtx(const size_t * lns, size_t rows) {
  
}

void input(int **mtx, const size_t * lns, int rows, const int * t, size_t n) {
  
}

void output(int ** mtx, size_t rows, const size_t * lns) {
  
}

void rm(int **mtx, size_t rows) {
  
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
	for(int i = 0; i < 15; ++i){
		std::cout << t[i] << " ";
	}
  return mtx;
}

int main() {
  
}
