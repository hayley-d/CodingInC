#include <stddef.h>

// return a *new, dynamically allocated* array with each element doubled.
int *maps(const int *arr, size_t size){
   int * result = malloc(size * sizeof(int));
  for(int i = 0; i < size; i++){
    result[i] = arr[i] * 2;
  }
  return result;
}

// Given x, fill result array with the first n multiples of x
void count_by(unsigned x, unsigned n, unsigned result[n]) {
  for(int i = 1; i <= n; i++) {
    result[i-1] = x * i;  
  }
}

// Given num return the sumation from 1 to num
int summation(int num) {
  int res = 0;
  int index = 1;
  do{
    res += index;
    index++;
  } while (index <= num);
  return res;
}

//Return the additive inverse of num
float opposite(float num) {
  return num * -1;
}
