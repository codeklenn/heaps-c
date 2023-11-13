

#ifndef _HEAPS_H_
#define _HEAPS_H_



typedef struct heap{
    int *array;
    int capacity;
    int size;
} HEAP;

void insert(HEAP *heap, int num);
void deleteNum(HEAP *heap);
HEAP *buildHeap(int *array, int size);

#endif