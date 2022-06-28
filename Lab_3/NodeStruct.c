
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct Node {
    int iValue;
    float fValue;
    struct Node *next;
};

int main() {

    struct Node *head = (struct Node*) malloc(sizeof(struct Node));
    head->iValue = 5;
    head->fValue = 3.14;
    // printf("The value of head: %p\n", head);
	// printf("Address of head: %p\n",&head);
    // printf("The value of iValue: %d\n", head->iValue);
    // printf("The address of iValue: %p\n", &(head->iValue));
    // printf("The value of fValue: %f\n", head->fValue);
    // printf("The address of fValue: %p\n", &(head->fValue));
    // printf("The value of next: %p\n", head->next);
    // printf("The address of next: %p\n", &(head->next));
	// Insert extra code here
	
    printf("head=%p, head->iValue=%d, head->fValue=%f, head->next=%p \n", head, head->iValue, head->fValue, head->next);
	printf("&head=%p,\n &head->iValue=%p,\n &head->fValue=%p,\n &head->next=%p \n", &head, &head->iValue, &head->fValue, &head->next);

    
	
	return 0;
}