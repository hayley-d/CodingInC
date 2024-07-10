//
// Created by User-PC on 10/07/2024.
//

#include "Pair.h"

template<typename T>
Pair<T>::Pair(T a, T b) : first(a), second(b){}

template<typename T>
T Pair<T>::getFirst() {return this->first;}

template<typename T>
T Pair<T>::getSecond() {return this->second;}

template<typename T>
void Pair<T>::setFirst(T f) {this->first = f;}

template<typename T>
void Pair<T>::setSecond(T s) {this->second = s;}


