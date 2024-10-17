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

// given the time in hours and you need to return the number of litres if 0.5 liters is drunk every 1 hour
int Liters(double time) {
  int liters = 0;
  int time_int = (int)time;
  if(time < 2) return 0;
  for(int i = 1; i < time_int; i += 2) {
    liters += 1;
  }
  return liters;
}

//Optimized/refactored version
// given the time in hours and you need to return the number of litres if 0.5 liters is drunk every 1 hour
int Liters(double time) {
  if(time < 2) return 0;
  return (int)(time/2);
}

//Optimized/refactored version
// given the time in hours and you need to return the number of litres if 0.5 liters is drunk every 1 hour
int Liters(double time) {
  return (int)(time/2);
}

// Create a function that takes an integer as an argument and returns "Even" for even numbers or "Odd" for odd numbers.
const char* even_or_odd(int number)
{
  number %= 2;
  switch(number) {
      case 0:
        return "Even";
        break;
      
      default:
        return "Odd";
        break;
  }
}

// Refactored
// Create a function that takes an integer as an argument and returns "Even" for even numbers or "Odd" for odd numbers.
const char* even_or_odd(int number)
{
  number %= 2;
  if(number == 0) return "Even";
  return "Odd";
}

// Refactored
// Create a function that takes an integer as an argument and returns "Even" for even numbers or "Odd" for odd numbers.
const char* even_or_odd(int number)
{
  return (number % 2) ? "Odd" : "Even";
}
