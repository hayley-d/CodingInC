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


