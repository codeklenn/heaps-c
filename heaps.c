#include <stdio.h>
#include <stdlib.h>
#include "heaps.h"

MINHEAP *initializeHeap(int capacity){
    MINHEAP *temp = (MINHEAP*)malloc(sizeof(MINHEAP));
    temp->capacity = capacity;
    temp->size = 0;
    temp->array = (int*)malloc(capacity * sizeof(int)); //Allocate memory for the pointer array.
    return temp;
}

void insert(MINHEAP *heap, int num){
    if(heap->size == 0){
        heap->array[heap->size] = num;
        heap->size++;
        return;
    }
    //...
}

int main(){
    return 0;
}