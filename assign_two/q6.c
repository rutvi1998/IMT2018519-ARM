//Circular Queue

#include<stdio.h>
#include<stdlib.h>

int size;
int *queue;
int front;
int rear;

void add_to_queue(int data){
	if((front == 0 && rear == size - 1) || (front == rear + 1)){
		printf("\nCIRCULAR QUEUE IS FULL. CANNOT ADD!\n");
	} else if(rear == -1){
		front = 0;
		rear = 0;
		queue[rear] = data;
	} else if(rear == size - 1){ 
		rear = 0;
		queue[rear] = data; 
	} else{
		queue[++rear] = data;
	}
}

int * remove_from_queue(){
	if(front == -1){	
		printf("\nCIRCULAR QUEUE IS EMPTY. CANNOT REMOVE!\n");
		return NULL;
	} else{
		int index = front;		
		if(front == rear){
			front = -1;
			rear = -1;
		} else if(front == size - 1){
			front = 0;
		} else{
			front++;
		}
		return &queue[index];
	}
}

void print(){
	int entries = 0;
	printf("\n");
	if(front <= rear){
		while(entries < front){
			printf("-\t");
			entries++;
		}
		printf("-->\t");
		while(entries <= rear){
			printf("%d\t", queue[entries++]);
		}
		printf("<--\t");
	} else {
		while(entries <= rear){
			printf("%d\t", queue[entries++]);
		}
		printf("<--\t");
		while(entries < front){
			printf("-\t");
			entries++;
		}
		printf("-->\t");
		while(entries < size){
			printf("%d\t", queue[entries++]);
		}
	}	
	printf("\n");
}

int main(){
	int choice, data, *removed = NULL;
	printf("Enter size of queue: ");
	scanf("%d", &size);
	queue = (int *)malloc(size * sizeof(int));
	front = -1;
	rear = -1;
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
