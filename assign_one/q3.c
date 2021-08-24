#include<stdio.h>

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
		if(array[i] % 2 == 0){
			count++;
		}
	}
	printf("There are %d even whole numbers!\n", count);
	return 0;
}
