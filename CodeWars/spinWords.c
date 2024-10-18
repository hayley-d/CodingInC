#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

void reverse_word(char* start, char* end){
  while(start < end) {
    char temp = *start;
    *start = *end;
    *end = temp;
    start++;
    end--;
  }
}

//Write a function that takes in a string of one or more words, and returns the same string, but with all words that have five or more letters reversed 
void spin_words(const char *sentence, char *result) {
  int word_start_index = 0;
  int length = strlen(sentence);
  
  strcpy(result,sentence); 
  
  for(int i = 0; i < length; i++){
    if(result[i] == ' ' || result[i] == '\0' ){
      if(i - word_start_index >= 5){
        // reverse word
        int end_index = i-1;
        int start_index = word_start_index;
        while(end_index > start_index){
          char temp = result[start_index];
          result[start_index] = result[end_index];
          result[end_index] = temp;
          start_index++;
          end_index--;
        }
      } 
      word_start_index = i + 1; // new word starts at next index if a space
      
    } else if(i == length -1){
       if(i - word_start_index >= 4){
        // reverse word
        int end_index = i;
        int start_index = word_start_index;
        while(end_index > start_index){
          char temp = result[start_index];
          result[start_index] = result[end_index];
          result[end_index] = temp;
          start_index++;
          end_index--;
        }
      } 
    }
  }
  
  
  
  result[length] = '\0';
}


