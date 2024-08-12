#include <stdio.h>
#include "mymalloc.h"
#include <stddef.h>

// Define a large block of memory to act as the heap
char memory[25000];

// Initialize the emptyBlock pointer to point to the start of the memory
struct block *emptyBlock = (void*)memory;

// Function to set metadata for a block
void metaData(struct block *ptr, size_t size, int isFree, struct block *next) {
    ptr->size = size;
    ptr->isFree = isFree;
    ptr->next = next;
}

// Function to split a block into two parts
void split(struct block *curr, size_t size) {
    // Create a new block right after the current block
    struct block *newFree = (void*)((void*)curr + size + sizeof(struct block));
    // Set metadata for the new block
    metaData(newFree, (curr->size) - size - sizeof(struct block), 1, curr->next);
    // Update the current block to have the new size and mark it as used
    curr->size = size;
    curr->isFree = 0;
    curr->next = newFree;
}

// Custom memory allocation function
void *MyMalloc(size_t block_size) {
    struct block *current;

    // Initialize memory if it is not already done
    if (!(emptyBlock->size)) {
        metaData(emptyBlock, 25000 - sizeof(struct block), 1, NULL);
        printf("----------The memory is initialized to %p----------\n", emptyBlock);
    }

    current = emptyBlock;

    // Find a suitable block for allocation
    while (((block_size > current->size) || (!(current->isFree))) && (current->next != NULL)) {
        printf("%p block is checked and it is used\n", (void*)current + sizeof(struct block));
        current = current->next;
    }

    // If an exact fitting block is found
    if ((current->size) == block_size) {
        current->isFree = 0;
        printf("\nExact fitting block allocated with the address %p\n\n", (void*)current + sizeof(struct block));
        return (void*)((void*)current + sizeof(struct block));
    }

    // If a larger block is found, split it
    else if ((current->size) > block_size) {
        split(current, block_size);
        printf("\nFitting block allocated with the address %p\n\n", (void*)current + sizeof(struct block));
        return (void*)((void*)current + sizeof(struct block));
    }

    // If no suitable block is found
    else {
        printf("\nSorry, Can't allocate memory.\n");
        return NULL;
    }
}

// Function to merge adjacent free blocks
void merge() {
    struct block *current = emptyBlock;
    while (current->next) {
        // If the current and next blocks are both free, merge them
        if ((current->isFree) && (current->next->isFree)) {
            current->size = current->size + current->next->size + sizeof(struct block);
            current->next = current->next->next;
        }
        current = current->next;
    }
}

// Custom memory free function
void MyFree(void *block) {
    struct block *current = block;
    // Adjust pointer to point to the block metadata
    current = (void*)((void*)(current) - sizeof(struct block));
    // Check if the block address is valid and if the block is currently in use
    if (((struct block*)memory <= current) && ((struct block*)(memory + 25000) >= current) && current->isFree == 0) {
        current->isFree = 1;
        merge();
        printf(">>%p block was successfully freed\n", (void*)current + sizeof(struct block));
    }
    else if (((struct block*)memory <= current) && ((struct block*)(memory + 25000) >= current) && current->isFree == 1) {
        printf("\nThe block is already freed\n");
    }
    else {
        printf("\nEnter a valid block address\n");
    }
}
