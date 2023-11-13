

#ifndef _HEAPS_H_
#define _HEAPS_H_



#include <stdlib.h>

// Structure representing a min-heap
typedef struct MINHEAP{
    int* array;    // Array to store heap elements
    int capacity;  // Maximum capacity of the heap
    int size;      // Current size of the heap
} MINHEAP;

// Function to initialize a min-heap
MINHEAP *initializeHeap(int capacity);

// Function to insert a new element into the min-heap
void insert(MINHEAP* heap, int value);

// Function to delete the minimum element from the min-heap
int deleteMin(MINHEAP* heap);

// Function to heapify a subtree rooted with the given index
void heapify(MINHEAP* heap, int index);

// Function to build a min-heap from an array of elements
MINHEAP *buildHeap(int* array, int size);

// Function to get the minimum element from the min-heap without deleting it
int getMin(MINHEAP* heap);

// Function to check if the min-heap is empty
int isEmpty(MINHEAP* heap);

// Function to check if the min-heap is full
int isFull(MINHEAP* heap);

// Function to free the memory allocated for the min-heap
void destroyHeap(MINHEAP* heap);
#endif