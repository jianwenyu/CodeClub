#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ARRAY_SIZE 10000
#define TARGET 20000 
int fuckingBinarySearch(int *array, int target, int size);

int main(void){
	
	int i = 0;
	int target = 0;
	int size = ARRAY_SIZE;
	int search = 5;
	int array[ARRAY_SIZE];
	printf("given the below array\n");
	for (i=0;i<size;i++){
		array[i] = 2*i;
		printf("%d is %d\n", i, array[i]);
	}
	printf("\n\n");
	// now try to find the value and the index that smaller than the desired search value and closest to the desired search value
	i = size;
/*	while((i-i_prev)==2){
		i_prev = i;
		printf("i_prev is %d\n", i_prev);
		if(array[i] > search){
			//all the values greater than index i is no good, 
			i = i/2;
		}
		else if(array[i] < search){
			i = (size - i)/2;
		}
		else{
			return i;
		}
		printf("i is %d\n", i);
	}*/
	target = fuckingBinarySearch(array, TARGET, size);
	printf("from fucking binary search %d == this is what we try to find %d . \n", target, TARGET);	
	



	return 0;
}

// find the fucking closest value to the target, smaller or equal
int fuckingBinarySearch(int *array, int target, int size){
	
	size = size/2; // this is fucking magic of the fucking binary search algorithm
	if (size == 1){
		return array[0];
	}
	if (array[size-2]<=target) {
		printf("%d <= target\n", array[size-2]);
		if (array[size-1]>target){
			printf("%d > target\n", array[size-1]);
			return array[size-2];
		}
		else if(array[size-1]==target){
			printf("%d == target\n", array[size-1]);
			return array[size-1];
		}
		else{
			printf("upper loop: array[%d] == %d\n", size-2, array[size-2]);
			return fuckingBinarySearch(array+size-1, target, size);
		}
	}
	else{
		printf("lower loop: array[%d] == %d\n", size-2, array[size-2]);
		return fuckingBinarySearch(array, target, size);
	}
}

