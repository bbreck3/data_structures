#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node *next;
} Node;

/*struct Node *front =NULL;
struct Node *rear =NULL;
*/

Node *enqueue(int data, Node *front, Node *rear){
	Node *temp = malloc(sizeof(Node));
	temp->data=data;
	temp->next=NULL;
	//printf("%d ", temp->data);
	/*if(rear==NULL){
		printf("Rear is NULL\n");
	}
	if(front==NULL){
		printf("Front is NULL\n");
	}*/
	if(front==NULL && rear==NULL){
		/*temp->data=data;
		temp->next=NULL;*/
		front =rear =temp;
		//printf("%d ", front->data);

		//printf("DEBUG\n");
		//return;
	}else{
		
		//rear->next=temp;
		rear =temp;
		rear->next=NULL;
		front->next=rear;
		
		//printf("%d ", rear->data);

	}
	return front;
	
}

int dequeue(Node *front, Node *rear){
	printf("%d\n",front->data );
	Node *temp=malloc(sizeof(Node));
	int data;
	if(front==NULL)
		return -1;
	if(front==rear){
		printf("DEBUG\n");
		//front temp->data;
		temp =rear;

	}else{
		temp = front;//front->next;
		printf("DEBUG\n");
		printf("%d ",temp->data);
	}
	data = temp->data;
	printf(" Data: %d\n",data );
	
	free(temp);
	return data;
}


int main(){
	int i;
	Node *front =NULL;
	Node *rear =NULL;

	for(i=0;i<10;i++){
		//printf("DEBUG");
		front =enqueue(i,front, rear);
	}
	//printf("%d\n", rear->data);
	for(i=0;i<10;i++){
		int temp = dequeue(front, rear);
		front=front->next;
		//printf(" %d ", temp);
		
	}
	

}
