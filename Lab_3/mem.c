
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

 int main() {
	int num;
	int *ptr;
	int **handle;

	num = 14;
	ptr = (int *)malloc(2 * sizeof(int));
	*ptr = num;
	handle = (int **)malloc(1 * sizeof(int *));
	*handle = ptr;
	printf("The value of num %d\n",num);
	printf("The address of &num %p\n",&num);
	printf("The address of &ptr %p\n",&ptr);
	printf("The address of num in ptr %p\n",ptr);
	printf("The value of *ptr %d\n",*ptr);
	printf("The address of &handle %p\n", &handle);
	printf("The address of handle %p\n", handle);
	printf("The value of *handle %p\n", *handle);
	printf("The value of **handle %d\n", **handle);
	// Insert extra code here
	/*
	printf("address of num=%p,address of ptr=%p, address of handle=%p\n", &num, &ptr, &handle);
	printf("value of num=%d,value of ptr=%p, value of handle=%p\n", num, ptr, handle);
	printf("value of *ptr=%d, value of *handle=%p\n", *ptr, *handle);

	*/
	return 0;
} 

