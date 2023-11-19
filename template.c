/*
 * Name: Klenn Jakek V. Borja	
 * Lab Section: U1L
 * Program Description: Simple C program for simulating and showing heaps. 
*/

#include "heap.h"
#include <stdio.h>
#include <stdlib.h>

int left(int index){
  return(2 * index); 
}

int right(int index){
  return(2 * index + 1); 
}

int parent(int index){
  return(index / 2); 
}

void printHeapHelper(HEAP *H, int index, int tabs){
	if(index > H->size) return;
	else{
		printHeapHelper(H, right(index), tabs + 1);
		for(int i=0; i<tabs; i++) printf("\t");
		printf("%d\n", H->heap[index]);
		printHeapHelper(H, left(index), tabs + 1);
	}
}

void printHeap(HEAP *H){
	if(H!=NULL && H->size>0){
		printHeapHelper(H, 1, 0);
	}else{
		printf("Empty heap!\n");
	}
}


// IMPLEMENT FUNCTIONS HERE

HEAP* createHeap(int maxSize){
	HEAP *temp = (HEAP*)malloc(sizeof(HEAP));
	temp->heap = (int*)malloc((maxSize+1)*sizeof(int));
	temp->maxSize = maxSize;
	temp->size = 0;
	return temp;
}

int isFull(HEAP *H){
	if(H->size + 1 == H->maxSize){ //added 1 since array is in 1-indexing.
		return 1; //heap is full
	}
	return 0; //heap is empty
}

int isEmpty(HEAP *H){
	if(H->size == 0){
		return 1; //heap is empty;
	}
	return 0; //heap is full
}

void clear(HEAP *H){
	H->size = 0;
	return;
}

void insert(HEAP *H, int key){
	//Disclaimer: insertion assuming that there are NO DUPLICATE VALUES.
	if(isFull(H)){ //If heap is full.
		printf("Heap is already full.\n");
		return;
	}
	//If heap is not empty, insert first, then increment size, then check if it violates
	//min-heap property.

	H->heap[H->size + 1] = key;
	H->size++;
	//Check if it violates min-heap property. If yes, swap.
	int tempIndex = H->size; //Create a temporary index that will be used for navigating over the heap
	while(tempIndex > 1){
		//maybe i can just combine it into: ... && key < H->heap[tempIndex/2]
			if(key < H->heap[tempIndex/2]){
				H->heap[tempIndex] = H->heap[tempIndex / 2]; //swap the parent
				tempIndex = tempIndex / 2;
			}
			else{
				break;
			}
	}
	H->heap[tempIndex] = key; //when the while loop ends, it means that the key has found its position.
	return;
}

int deleteM(HEAP *H){
    //check if heap is empty:
    if(isEmpty(H)){
        printf("There is nothing to delete.\n");
        return -1; //placeholder value
    }
    int deleted_key = H->heap[1];

    //delete minimum value (root node)
    //keep in mind that your H->size here is the rightmost leaf node
    int temp = H->heap[H->size];
    H->heap[H->size] = deleted_key;
    H->size--;
    //Check whether it violates the min-heap rule. If yes, do a percolate up.
    int tempIndex = 1; //starting traversal index
    int key = H->heap[tempIndex]; //keep track of the key that will be swapped
    while(tempIndex < H->size){
		if(H->size == 1){ //If no children (or deleting the root node)
			break;
		} 
        //get the greater of the child:
        if(tempIndex*2 > H->size){ //if no left child
            break;
        }
        else if(tempIndex*2 == H->size){ //if only one child
            if(H->heap[tempIndex*2] < H->heap[tempIndex]){ //if right child is smaller
                H->heap[tempIndex] = H->heap[tempIndex*2];
                tempIndex = tempIndex*2;
            }
            else{ //if left child is smaller
                break;
            }
        }
        else{ //if two children
            if(H->heap[tempIndex*2] < H->heap[(tempIndex*2)+1]){ //if left child is smaller
                H->heap[tempIndex] = H->heap[tempIndex*2];
                tempIndex = tempIndex*2;
            }
            else{ //if right child is smaller
                H->heap[tempIndex] = H->heap[(tempIndex*2)+1];
                tempIndex = (tempIndex*2)+1;
            }
        }
    }
    H->heap[tempIndex] = temp; //overwrite the root node with the value that was just deleted
    return deleted_key;
}
int *heapSort(HEAP *H){
	return H->heap;
}

void EprintHeap(HEAP *H){
	for(int i = 1; i<=H->maxSize; i++){
		if(H->heap[i] == '\0') break; //End of the array
		printf("%d ", H->heap[i]);
	}

}
int main(){

	char command;
	int key, result, type;
    int* sorted;

	HEAP *H = createHeap(30);

	while(1){
		scanf(" %c", &command);

		switch(command){
			case '+':
				scanf("%d", &key);
				printf("Inserting key: %d...\n", key);
				insert(H, key);
				break;
			case '-':
				printf("Removing root from tree...\n");
				result = deleteM(H); // result is unused
				break;
			case 'p':
				printf("Printing the heap (rotated +90 degrees)...\n");
				printHeap(H);
				printf("\n");
				break;
			case 'E':
				printf("Heap %s empty.\n", isEmpty(H)?"is":"is not");
				break;
			case 'F':
				printf("Heap %s full.\n", isFull(H)?"is":"is not");
				break;
			case 'C':
				printf("Removing all contents...\n");
				clear(H);
				break;
			case '~':
				printf("The sorted version of the heap:\n");
				sorted = heapSort(H);
				for(key=1; key <= H->maxSize; key++){
					if(sorted[key] == '\0') break;
					printf("%4d", sorted[key]);
					
				}
				printf("\n");
				free(sorted);
				break;
			case 'Q':
				free(H->heap);
				free(H);
				return 0;
			case 'P': 
				printf("Printing the heap w/o tree:\n");
				EprintHeap(H);
				break;
			default:
				printf("Unknown command: %c\n", command);
		}
	}

	return 0;
}