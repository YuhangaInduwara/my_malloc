#ifndef MYMALLOC_H
#define MYMALLOC_H

struct block{
	size_t size;
	int isFree;
	struct block *next;
};

void *MyMalloc(size_t block_size);
void MyFree(void *block);

#endif