void count_by(unsigned x, unsigned n, unsigned result[n]) {
  for(int i = 1; i <= n; i++) {
    result[i-1] = x * i;  
  }
}
