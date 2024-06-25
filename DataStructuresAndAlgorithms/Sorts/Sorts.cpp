//
// Created by hayley on 2024/06/25.
//

#include "Sorts.h"

void Sorts::bubbleSort(std::vector<int> &arr) {
    for(int i = arr.size()-1; i > 0;i--) {
        for(int j = 0; j < i; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void Sorts::selectoionSort(std::vector<int> &arr) {
    int size = arr.size();
    for(int i = 0; i < size;i++) {
        int minIndex = i;
        for(int j = i+1; j< size; j++) {
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if(i != minIndex) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

void Sorts::insertionSort(std::vector<int> &arr) {
    int size = arr.size();
    for(int i = 1; i < size; i++) {
        int temp = arr[i];
        int j = i -1;
        while(j >= 0 && temp < arr[j]) {
            arr[j+1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }
}

void Sorts::mergeSort(std::vector<int> &arr) {
    int size = arr.size();
    int leftIndex = 0;
    int rightIndex = size-1;
    int midIndex = (size/2)-1;

    mergeSortHelper(arr,leftIndex,rightIndex);
}


void Sorts::merge(std::vector<int> &arr, int leftIndex, int midIndex, int rightIndex) {
    int leftArraySize = midIndex-leftIndex +1;
    int rightArraySize = rightIndex-midIndex;

    std::vector<int> leftArray;
    std::vector<int> rightArray;

    for(int i = 0; i < leftArraySize; i++) {
        leftArray[i] = arr[i+leftIndex];
    }
    for(int i = 0; i < rightArraySize; i++) {
        rightArray[i] = arr[i+midIndex+1];
    }

    int index = leftIndex;
    int i = 0;
    int j = 0;

    while(i < leftArraySize && j < rightArraySize) {
        if(leftArray[i] <= rightArray[j]) {
            arr[index] = leftArray[i];
            index++;
            i++;
        }else {
            arr[index] = rightArray[j];
            index++;
            j++;
        }
    }

    while(i < leftArraySize) {
        arr[index] = leftArray[i];
        index++;
        i++;
    }

    while(j < rightArraySize) {
        arr[index] = rightArray[j];
        index++;
        j++;
    }
}

void Sorts::mergeSortHelper(std::vector<int> &arr, int leftIndex, int rightIndex) {
    if(leftIndex >= rightIndex) return;

    int midIndex = leftIndex + (rightIndex - leftIndex) /2;
    mergeSortHelper(arr,leftIndex,midIndex);
    mergeSortHelper(arr,midIndex+1,rightIndex);

    merge(arr,leftIndex,midIndex,rightIndex);
}




