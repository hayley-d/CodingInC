//
// Created by hayley on 2024/06/25.
//

#ifndef SORTS_H
#define SORTS_H

#include<vector>

class Sorts {
public:
   void bubbleSort(std::vector<int>& arr);
   void quickSort(std::vector<int>& arr);
   void selectoionSort(std::vector<int>& arr);
   void insertionSort(std::vector<int>& arr);
   void mergeSort(std::vector<int>& arr);

private:
   void merge(std::vector<int>& arr, int leftIndex, int midIndex,int rightIndex);
   void mergeSortHelper(std::vector<int>& arr, int leftIndex,int rightIndex);
};



#endif //SORTS_H
