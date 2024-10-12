#include <string>

std::string createPhoneNumber(const int arr [10]){
  std::string number = "(";
  for(int i = 0; i < 10; i++){
    if(i == 2){
      number += std::to_string(arr[i]) + ") "; 
      continue;
    }
    if(i == 5){
       number += std::to_string(arr[i]) + "-"; 
      continue;
    }
    number += std::to_string(arr[i]);
  }
  return number;
}
