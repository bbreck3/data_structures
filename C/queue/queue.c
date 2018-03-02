#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node *next;
} *Node;

struct Node *front =NULL;
struct Node *rear =NULL;


void enqueue(int data){
	struct Node *temp = (struct Node*)malloc(sizeof(struct Node*));
	temp->data=data;
	temp->next=NULL;
	if(front==NULL && rear==NULL){
		front =rear =temp;
		return;
	}
	rear->next=temp;
	rear =temp;

}

int dequeue(){
	struct Node *temp=front;
	if(front==NULL)
		return;
	if(front==rear)
		front =rear=NULL;
	else{
		front = front->next;
	}
	int data = temp->data;
	free(temp);
	return data;
}


int main(){
	int i;
	for(i=0;i<10;i++){
		enqueue(i);
	}
	for(i=0;i<10;i++){
		int temp = dequeue();
		printf(" %d ", temp);
		
	}
	

}
