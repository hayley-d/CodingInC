#include <stdio.h>
char *human_readable_time (unsigned seconds, char *time_string)
{
  int hours = 0;
  int min = 0;
    
  hours = seconds/3600; 
  seconds = seconds - (3600*hours);
  
  min = seconds/60;
  seconds = seconds - (60*min);
  
  sprintf(time_string,"%02d:%02d:%02d",hours,min,seconds);
  
	return time_string; 
}
