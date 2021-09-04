//Simple Queue

#include<stdio.h>
#include<stdlib.h>

int size;
int *queue;
int head;
int tail;

void add_to_queue(int data){
	if(tail == size - 1)
		printf("\nQUEUE IS FULL. CANNOT ADD!\n");
	else if(tail == -1){
		head = 0;
		tail = 0;
		queue[tail] = data;
	} else{
		queue[++tail] = data;
	}
}

int * remove_from_queue(){
	if(head == -1){	
		printf("\nQUEUE IS EMPTY. CANNOT REMOVE!\n");
		return NULL;
	} else{
		int index = head;
		if(head == tail){
			head = -1;
			tail = -1;
		} else{
			head++;
		}		
		return &queue[index];
	}
}

void print(){
	int entries = 0;
	printf("\n");
	while(entries < head){
		printf("-\t");
		entries++;
	}
	while(entries <= tail){
		printf("%d\t", queue[entries++]);
	}
	while(entries < size){
		printf("-\t");
		entries++;
	}
	printf("\n");
}

int main(){
	int choice, data, *removed = NULL;
	printf("Enter size of queue: ");
	scanf("%d", &size);
	queue = (int *)malloc(size * sizeof(int));
	head = -1;
	tail = -1;
	do{
		printf("\n1. Add\n2. Remove\n3. Print\n4. Exit\nEnter choice (1/2/3/4): ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				printf("\nEnter data: ");
				scanf("%d", &data);
				add_to_queue(data);
				break;
			case 2:
				removed = remove_from_queue();
				if(removed != NULL){
					printf("\n%d removed...\n", *removed);
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
