#include <stdio.h>
#include <stdlib.h>
#define STRINGSIZE 1024

void printarray(char** array, int n) {
	for (int i = 0; i < n; ++i)
		printf("[%d]: %s\n", i+1, array[i]);
}

void array_add(char** array, int n) {
	array[n] = malloc(STRINGSIZE*sizeof(char));
	scanf("%s", array[n]);
}

void array_rem(char** array, int n) {
	int id;	
	printf("Which id we remove: \n");
	scanf("%d", &id);
	id--;
	for (int i = id; i < n-1; i++)
		array[i] = array[i+1];
	array[n-1] = NULL;
}

int main() {
	int n1, n2, MAXSIZE;
	printf("Max size of arrays: ");
	scanf("%d", &MAXSIZE);
	printf("Enter num of elements of array 1: ");
	scanf("%d", &n1);
	getchar();
	
	char** array1 = malloc(MAXSIZE*sizeof(char*));
	for (int i = 0; i < n1; ++i)
		array1[i] = malloc(STRINGSIZE*sizeof(char));
	
	printf("Enter elements:\n");
	for (int i = 0; i < n1; ++i)
		scanf("%s", array1[i]);
	
	printf("Enter size of array 2: ");
	scanf("%d", &n2);
	getchar();
	
	char** array2 = malloc(MAXSIZE*sizeof(char*));
	for (int i = 0; i < n2; ++i)
		array2[i] = malloc(STRINGSIZE*sizeof(char));
	
	printf("Enter elements:\n");
	for (int i = 0; i < n2; ++i)
		scanf("%s", array2[i]);
	
	int cmd = -1;
	while(cmd != 0) {
		printf("Enter cmd:\n1. Add to 1\n2. Add to 2\n3. Remove from 1\n4. Remove from 2\n5. Print all\n");
		scanf("%d", &cmd);
		switch(cmd) {
			case 0: break;
			case 1: array_add(array1, n1); n1++;break;
	case 2: array_add(array2, n2); n2++;break;
			case 3: array_rem(array1, n1); n1--; break;
			case 4: array_rem(array2, n2); n2--;break;
			case 5: printf("Array 1:\n");printarray(array1, n1); printf("Array 2:\n");printarray(array2, n2); break;
			default: printf("KEK\n"); break;
			
		}
		
	}
	return 0;
}
