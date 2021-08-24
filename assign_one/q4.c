#include<stdio.h>

void merge(int *array, int left, int middle, int right){
	int size = right - left + 1, temp[size], i = left, j = middle + 1, k = 0;
	while(i <= middle && j <= right){
		if(array[i] < array[j]){
			temp[k++] = array[i++];
		} else{
			temp[k++] = array[j++];
		}
	}
	while(i <= middle){
		temp[k++] = array[i++];
	}
	while(j <= right){
		temp[k++] = array[j++];
	}
	for(int i = 0; i < size; i++){
		array[left + i] = temp[i];
	}
}

void mergeSort(int *array, int left, int right){
	if(left < right){
		int middle = (left + right) / 2;
		mergeSort(array, left, middle);
		mergeSort(array, middle + 1, right);
		merge(array, left, middle, right);
	}
}

int main(){
	int array[20], valid, count = 0;
	for(int i = 0; i < 20; i++){
		valid = 0;
		while(!valid){
			printf("Enter whole number-%d: ", i + 1);
			scanf("%d", &array[i]);
			if(array[i] >= 0){
				valid = 1;
			} else{
				printf("INVALID!\n");
			}
		}
	}
	mergeSort(array, 0,  sizeof(array) / sizeof(int) - 1);
	printf("The given whole numbers in ascending order are:\n");
	for(int i = 0; i < 20; i++){
		printf("%d ", array[i]);
	}
	printf("\n");
	return 0;
}
