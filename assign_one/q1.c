#include<stdio.h>

int main(){
	int x, y, z, valid = 0;
	while(!valid){
		printf("Enter first whole number: ");
		scanf("%d", &x);
		if(x >= 0){
			valid = 1;
		} else{
			printf("INVALID!\n");
		}
	}
	valid = 0;
	while(!valid){
		printf("Enter second whole number: ");
		scanf("%d", &y);
		if(y >= 0){
			valid = 1;
		} else{
			printf("INVALID!\n");
		}
	}
	valid = 0;
	while(!valid){
		printf("Enter third whole number: ");
		scanf("%d", &z);
		if(z >= 0){
			valid = 1;
		} else{
			printf("INVALID!\n");
		}
	}
	if(x >= y){
		if(x >= z){
			printf("%d is the largest whole number!\n", x);	
		} else{
			printf("%d is the largest whole number!\n", z);
		}
	} else{
		if(y >= z){
			printf("%d is the largest whole number!\n", y);	
		} else{
			printf("%d is the largest whole number!\n", z);
		}
	}
	return 0;
}
