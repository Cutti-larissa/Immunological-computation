#include <iostream>
#include <vector>
#include "MinHeap.hpp"
//precisa de adaptação para utilização no RNS (usar template??)

MinHeap(int capacity){
    this->size = 0;
    this->capacity = capacity;
    this->array.resize(capacity);
}
        
~MinHeap(); //default

void heapify(int i){
    int smallest = i;
    int left = 2*i +1;
    int rigth = 2*i +2;
    if (left < size && array[left].distancia < array[smallest].distancia)
        smallest = left;
    if (rigth < size && array[rigth].distancia < array[smallest].distancia)
        smallest = rigth;
    if (smallest != i){
        std::swap(array[i], array[smallest]);
        heapify(smallest);
    }
}

void buildHeap(const vector<struct dado>& arr){
    std::copy(arr.begin(), arr.end(), this->array.begin());

    for (int i = ((this->size) - 1) / 2; i >= 0; --i){
        heapify(i);
    }
}

dado extractMin(){
    if(size <= 0)
        return -1; //empty
    if(size == 1){
        size--;
        return array[0];
    }

    struct dado root = array[0];
    array[0] = array[size -1];
    size--;
    heapify(0);
    return root;
}
