#include <stddef.h>

size_t countBits(unsigned value)
{
    // This will count the number of set bits
	  size_t count = 0;
    // Right shift (technically dividing by 2) 
    for (; value; value >>= 1) {
      // if the least significant bit is 1
      if ( value & 1 )  {
        count++;
      }
    }
    return count;
}
