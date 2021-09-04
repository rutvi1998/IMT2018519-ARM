//Empty Descending Stack

#include<stdio.h>
#include<stdlib.h>

int size;
int *stack;
int head;

void Push(int data){
	if(head == -1){
		printf("\nSTACK IS FULL. CANNOT PUSH!\n");
		return;
	}
	stack[head--] = data;
}

int * Pop(){
	if(head == size - 1){
		printf("\nSTACK IS EMPTY. CANNOT POP!\n");
		return NULL;
	}
	return &stack[++head];
}

void print(){
	int entries = size - 1;
	printf("\n");
	while(entries > head){
		printf("%d\n", stack[entries--]);
	}
	while(entries >= 0){
		printf("-\n");
		entries--;
	}
}

int main(){
	int choice, data, *popped = NULL;
	printf("Enter size of stack: ");
	scanf("%d", &size);
	stack = (int *)malloc(size * sizeof(int));
	head = size - 1;
	do{
		printf("\n1. Push\n2. Pop\n3. Print\n4. Exit\nEnter choice (1/2/3/4): ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				printf("\nEnter data: ");
				scanf("%d", &data);
				Push(data);
				break;
			case 2:
				popped = Pop();
				if(popped != NULL){
					printf("\n%d popped...\n", *popped);
				}
				break;
			case 3:
				print();
				break;
			case 4:
				printf("\nExiting...\n");
				break;
			default:
				printf("\nINVALID CHOICE!\n");				
		}
	} while(choice != 4);
	return 0;
}
