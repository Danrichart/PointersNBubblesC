//bubble.c
//famous bubble sort
//implement the swap algorithm with pointers

#include <stdio.h>
#include <stdlib.h>
#define MAX 9

//function prototypes
void printValues();
void sort();
void swap(int*, int*);
void randomN();
int check_array(int);

int values[9] = { 0 };

int main(){
	randomN();
	printf("Before: \n");
	printValues();
	sort();
	printf("After: \n");
	printValues();
	return(0);
} // end main

void printValues(){
	//initializes for loop
	int i;
	//used for display formating
	printf("[");
	for (i = 0; i < MAX; i++){
		//print values of array
		printf(" %d", values[i]);
	}
	printf(" ] \n");
}

void sort(){
	// assigns two pointers to send swap function
	int * ptr1;
	int * ptr2;

	//initializes two for loops to transverse array
	int i;
	int x;
	for (i = 0; i < MAX - 2; i++){
		for (x = 0; x < MAX - 1; x++){
			//uses if statement to compare element x and the one next to it
			if (values[x] > values[x + 1]){
				//points the ptr1 and ptr2 to location value[x] and value[x+1]
				ptr1 = &values[x];
				ptr2 = &values[x + 1];
				//send pointers 1 and 2 to swap
				swap(ptr1, ptr2);
				//prints array
				printValues();
			}
		}
	}
}

void swap(int * ptr1, int * ptr2){
	//creates a temp variable to hold the highest variable at values[x]
	int temp;
	//assigns the highest value to the temp
	temp = *ptr1;
	//assigns lowest value to the values[x] element
	*ptr1 = *ptr2;
	// assigns highest value to values[x+1] element, using stored value in temp
	*ptr2 = temp;
}

void randomN(){
	int i;
	int check;
	for (i = 0; i < MAX; i++){	
		int rnd = rand() % 10;
		check = check_array(rnd);
		if (check == 1){
			values[i] = rnd;
		}
		else {
			i--;
		}		
	}
}

int check_array(int rnd){
	int x; 
	for (x = 0; x < MAX; x++){
		if (rnd == values[x]){
			return 0;
		}
	}
	return 1;

}

