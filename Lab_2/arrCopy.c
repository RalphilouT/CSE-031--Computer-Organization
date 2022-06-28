#include <stdio.h>
#include <stdint.h> 
#include <stdlib.h>
#include <string.h>

void printArr(int *a, int size, char *name){
    
    printf("%s array's contents: ",name);
	for(int i = 0; i<size;i++)
    {
        printf("%d ", *(a+i));
    }
    printf("\n");
    
}

int* arrCopy(int *a, int size){
    int * arr = (int *) malloc(size*sizeof(int));
    for(int i =0; i<size;i++)
    {
        *(arr+i) = *(a+i);

    }
    
    return (arr);
    
}

int main(){
    int n;
    int *arr;
    int *arr_copy;
    int i;
    printf("Enter the size of array you wish to create: ");
    scanf("%d", &n);
    

    //Dynamically create an int array of n items
    arr = (int *) malloc (n*sizeof(int));

    //Ask user to input content of array
	for(int i = 0; i<n;i++)
    {
        printf("Enter the array element #%d: ",i+1);
        scanf("%d",(arr+i));
    }
	printf("\n");
/*************** YOU MUST NOT MAKE CHANGES BEYOND THIS LINE! ***********/
	
	//Print original array
    printArr(arr, n, "Original");

	//Copy array
    arr_copy = arrCopy(arr, n);

	//Print new array
    printArr(arr_copy, n, "Copied");

    printf("\n");

    return 0;
}