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

void insert(MINHEAP *heap, int num) {
    int temp_index;
    if (heap->size == heap->capacity) {
        printf("Heap is already full.\n");
        return;
    }

    heap->array[heap->size + 1] = num;
    heap->size++;

    temp_index = heap->size;
    while (temp_index > 1 && num < heap->array[temp_index / 2]) {
        heap->array[temp_index] = heap->array[temp_index / 2];
        temp_index /= 2;
    }
    heap->array[temp_index] = num;
}

void printHeap(MINHEAP *heap){
    for(int i = 1; i < heap->size+1; i++){ //1 indexing
        printf("%d ", heap->array[i]);
    }
    return;
}
int main(){
    MINHEAP *heap = initializeHeap(10);
    insert(heap, 10);
    insert(heap, 20);
    insert(heap, 13);
    insert(heap, 22);
    insert(heap, 31);
    insert(heap, 15);
    insert(heap, 18);
    insert(heap, 8);
    printHeap(heap);
    return 0;
}