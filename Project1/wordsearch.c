#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declarations of the two functions you will implement
// Feel free to declare any helper functions
void printPuzzle(char** arr, int n);
void searchPuzzle(char** arr, int n, char** list, int listSize);

// Main function, DO NOT MODIFY (except line 52 if your output is not as expected -- see the comment there)!!!	
int main(int argc, char **argv) {
    int bSize = 15;
	if (argc != 2) {
		fprintf(stderr, "Usage: %s <puzzle file name>\n", argv[0]);
		return 2;
	}
    int i, j;
    FILE *fptr;
    char **block = (char**)malloc(bSize * sizeof(char*));
	char **words = (char**)malloc(50 * sizeof(char*));

    // Open file for reading puzzle
    fptr = fopen(argv[1], "r");
    if (fptr == NULL) {
        printf("Cannot Open Puzzle File!\n");
        return 0;
    }

	// Read puzzle block into 2D arrays
    for(i = 0; i < bSize; i++) {
        *(block+i) = (char*)malloc(bSize * sizeof(char));

        fscanf(fptr, "%c %c %c %c %c %c %c %c %c %c %c %c %c %c %c\n", *(block+i), *(block+i)+1, *(block+i)+2, *(block+i)+3, *(block+i)+4, *(block+i)+5, *(block+i)+6, *(block+i)+7, *(block+i)+8, *(block+i)+9, *(block+i)+10, *(block+i)+11, *(block+i)+12, *(block+i)+13, *(block+i)+14 );
    }
	fclose(fptr);

	// Open file for reading word list
	fptr = fopen("states.txt", "r");
	if (fptr == NULL) {
        printf("Cannot Open Words File!\n");
        return 0;
    }
	
	// Save words into arrays
	for(i = 0; i < 50; i++) {
		*(words+i) = (char*)malloc(20 * sizeof(char));
		fgets(*(words+i), 20, fptr);		
	}
	
	// Remove newline characters from each word (except for the last word)
	for(i = 0; i < 49; i++) {
		*(*(words+i) + strlen(*(words+i))-2) = '\0'; // Change -2 to -1 if line 58 outputs words with the last character missing
	}
	
	// Print out word list
	printf("Printing list of words:\n");
	for(i = 0; i < 50; i++) {
		printf("%s\n", *(words + i));		
	}
	printf("\n");
	
	// Print out original puzzle grid
    printf("Printing puzzle before search:\n");
    printPuzzle(block, bSize);
	printf("\n");

	// Call searchPuzzle to find all words in the puzzle
	searchPuzzle(block, bSize, words, 50);
	printf("\n");
	
	// Print out final puzzle grid with found words in lower case
    printf("Printing puzzle after search:\n");
    printPuzzle(block, bSize);
	printf("\n");
	
    return 0;
}

void printPuzzle(char** arr, int n) {
	// This function will print out the complete puzzle grid (arr). It must produce the output in the SAME format as the samples in the instructions.
	// Your implementation here
	for(int i = 0; i<n;i++)
	{
		for(int j=0; j<n; j++)
		{
			printf("%c ",*(*(arr+i)+j));
		}
		printf("\n");
	}


}

void searchPuzzle(char** arr, int n, char** list, int listSize) {
	// This function checks if arr contains words from list. If a word appears in arr, it will print out that word and then convert that word entry in arr into lower case.
	// Your implementation here
	
	char **change = (char**)malloc(n * sizeof(char*));
	char **arr1 = (char**)malloc((n+2) * sizeof(char*));
	char **print = (char**)malloc(listSize * sizeof(char*));
	for(int i = 0; i < listSize ; i++)
	{
		*(print+i) = (char*)malloc(listSize * sizeof(char));
		int j =0;
		while(*(*(list+i)+j)!='\0')
		{
			*(*(print+i)+j) = *(*(list+i)+j);
			j++;
		}
		*(*(print+i)+j+1) = '\0';
	}
	for(int i = 0; i < n; i++) {
        *(change+i) = (char*)malloc(n * sizeof(char));
		
	}
	for(int i = 0; i <= n+1; i++) {
        *(arr1+i) = (char*)malloc(n * sizeof(char));
		
	}
	for(int find = 0; find <listSize;find++)
	{
		for (int i = 0; *(*(list+find)+i)!='\0'; i++) 
		{
			if(*(*(list+find)+i) >= 'a' && *(*(list+find)+i) <= 'z') {
				*(*(list+find)+i) = *(*(list+find)+i) - 32;
			}
		}
	}
	//printf("Words found: \n");
	for(int g = 0;g<n;g++)
	{
		for(int k = 0;k<n;k++)
		{
			*(*(change+g)+k) = *(*(arr+g)+k);
			*(*(arr1+g+1)+k) = *(*(arr+g)+k);
		}
	}
	for(int i = 0 ; i<n;i++)
	{
		*(*(arr1+16)+i) = 'X';
		*(*(arr1+0)+i) = 'X';
	}
	int recall = 0;
	int decision = 0;
	int found = 0;
	for(int g = 0;g<n;g++)
	{
		for(int k = 0;k<n;k++)
		{
			for(int find = 0; find <listSize;find++)
			{
				int d = 0;
				if(*(*(list+find)+0)==*(*(arr+g)+k))
				{
					found  = 1;	
				}
				if (found == 1 )
				{
					int k1 = k;
								
					while(*(*(list+find)+d) == *(*(arr+g)+k1))
					{
						//Horizontal
						if(*(*(list+find)+d+1) == '\0')
						{
							//printf("Words found: %s\n", *(list + find));
							printf("Words found: %s\n", *(print + find));
							for(int j = k ; j < k1+1;j++)
							{
								if(*(*(change+g)+j) >= 'A' && *(*(change+g)+j) <= 'Z') 
								{
									*(*(change+g)+j) = *(*(change+g)+j) + 32;
								}
								//
							}
							
						}
						
						k1++;
						d++;	
					}
					int d = 0;
					int k3 = k;
					int k2 = g;
					while(*(*(list+find)+d) == *(*(arr1+k2+1)+k3) && (k2 <=14))
					{
						//Down
						if(*(*(list+find)+d+1) == '\0')
						{
							//printf("Words found: %s\n", *(list + find));
							printf("Words found: %s\n", *(print + find));
							for(int j = g; j < k2+1;j++)
							{
								if(*(*(change+j)+k) >= 'A' && *(*(change+j)+k) <= 'Z') 
								{
									*(*(change+j)+k) = *(*(change+j)+k) + 32;
								}
							}
						}
						d++;
						k2++;
					}
					d = 0;
					k3 = k;
					k2 = g;
					while(*(*(list+find)+d) == *(*(arr1+k2+1)+k3) && (k2 >= 0))
					{
						//Up
						if(*(*(list+find)+d+1) == '\0')
						{
							//printf("Words found: %s\n", *(list + find));
							printf("Words found: %s\n", *(print + find));
							for(int j = g; j >= k2;j--)
							{
								if(*(*(change+j)+k) >= 'A' && *(*(change+j)+k) <= 'Z') 
								{
									*(*(change+j)+k) = *(*(change+j)+k) + 32;
								}
							}
						}
						d++;
						k2--;
					}
					
					d = 0;
					k3 = k;
					k2 = g;
					while(*(*(list+find)+d) == *(*(arr1+k2+1)+k3) && k2 <= 14 && k3 <= 14)
					{
						//down and right
						if(*(*(list+find)+d+1) == '\0')
						{
							//printf("Words found: %s\n", *(list + find));
							printf("Words found: %s\n", *(print + find));
							for(int j = 0; j < d+1;j++)
							{
								if(*(*(change+g+j)+k+j) >= 'A' && *(*(change+g+j)+k+j) <= 'Z') 
								{
									*(*(change+g+j)+k+j) = *(*(change+g+j)+k+j) + 32;
								}
							}
						}
						d++;
						k2++;
						k3++;
					}
					d = 0;
					k3 = k;
					k2 = g;
					while(*(*(list+find)+d) == *(*(arr1+k2+1)+k3) && k2 >= 0 && k3 <= 14)
					{
						//up and right
						if(*(*(list+find)+d+1) == '\0')
						{
							//printf("Words found: %s\n", *(list + find));
							printf("Words found: %s\n", *(print + find));
							for(int j = 0; j < d+1;j++)
							{
								if(*(*(change+g-j)+k+j) >= 'A' && *(*(change+g-j)+k+j) <= 'Z') 
								{
									*(*(change+g-j)+k+j) = *(*(change+g-j)+k+j) + 32;
								}
							}
						}
						d++;
						k2--;
						k3++;
					}		
					
				}
			}
				
		}
	}
	//printPuzzle(arr1,n);
	
	for(int g = 0;g<n;g++)
	{
		for(int k = 0;k<n;k++)
		{
			*(*(arr+g)+k) = *(*(change+g)+k);
		}
	}
	
}
//#8 Delaware