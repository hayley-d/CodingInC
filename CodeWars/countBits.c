#include <stddef.h>
#include <stdio.h>

size_t countBits(unsigned value)
{
  int binary_number[64];
  // Initialize array to 0
  for(int i = 0; i < 64; i++){
    binary_number[i] = 0;
  }
  
  int index = 0;
  
  // Binary conversion
  while(value > 0){
    binary_number[index] = value % 2;
    index++;
    value /= 2;
  }
 
  int set_bits = 0;
  // Count set bits
  for(int j = 0; j < 32; j++){
    if(binary_number[j] == 1){
      set_bits++;
    }
  }
	return set_bits;
}
