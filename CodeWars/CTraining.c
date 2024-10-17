void count_by(unsigned x, unsigned n, unsigned result[n]) {
  for(int i = 1; i <= n; i++) {
    result[i-1] = x * i;  
  }
}

int summation(int num) {
  int res = 0;
  int index = 1;
  do{
    res += index;
    index++;
  } while (index <= num);
  return res;
}
