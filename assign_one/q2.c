#include<stdio.h>

int main(){
	int array[15], valid, largest = -1;
	for(int i = 0; i < 15; i++){
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
		if(array[i] > largest){
			largest = array[i];
		}
	}
	printf("%d is the largest whole number!\n", largest);
	return 0;
}
