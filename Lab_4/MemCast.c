#include <stdio.h>

int main(){
	int i;
	int four_ints[4];
	char* four_c;
	
	for(i = 0; i < 4; i++)
        four_ints[i] = 2;
	
	printf("%x\n", four_ints[0]);
	
    four_c = (char*)four_ints;

	for(i = 0; i < 4; i++)
        four_c[i] = 'A' + i; // ASCII value of 'A' is 65 or 0x41 in Hex.
		//four_c[i] = 1;
    // Add your code for the exercises here:
	printf("%x\n", four_ints[0]);
	printf("%x\n", four_ints[1]);
	printf("%x\n", four_ints[2]);
	printf("Address of four_ints: %p and adress of four_c: %p\n",four_ints, four_c);
	for(i = 0; i < 4; i++)
	{
		printf("Address of four_ints[%d]: %p\n",i,&four_ints[i]);
		printf("Address of four_ints[%d]: %x\n",i, four_ints[i]);
	}
	for(i = 0; i < 4; i++)
	{
		printf("Address of four_c[%d]: %p\n",i,&four_c[i]);
		printf("Address of four_c[%d]: %x\n",i,four_c[i]);
	}
	return 0;
}