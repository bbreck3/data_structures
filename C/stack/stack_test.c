#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	struct Node *next;
} Node;


void push(int data, Node *top){
	Node *temp = malloc(sizeof(Node));
	Node *current = malloc(sizeof(Node));
	//temp->data=data;
	temp->data=data;
	printf("data: %d, top->data: %d",data, top->data );
	top = malloc(sizeof(Node));
	if(top==NULL){
		temp->next =top;
		top= temp;
		//top->next=NULL;
	}else{

	current = top;
	//top = malloc(sizeof(Node));
	temp->next=current->next;
	current->next=temp;
	temp->data=data;
	//printf("%d\n", temp->data);
	}
	printf("%d\n", current->next);
	//return top;
	/*temp->data =data;
	temp->next=top;
	top = temp;
	return top;*/
	//free(temp);
}


int is_empty(Node *top){
	//return(top==NULL)
	if(top==NULL){
		return 1;
	}
		return 0;
}


int pop(Node *top){
	Node *temp=malloc(sizeof(Node));
	if(is_empty(top)){
		return -1;
	}
	temp = top;
	int data = temp->data;
	printf("%d ", data);
	top = top->next;
	//free(temp);
	return data;
}
int main(){
	Node *top =malloc(sizeof(Node));


	for(int i=0; i<10; i++){
		top->data=i;

		push(i,top);
		//printf("DEBUG: %d\n", top->data);
	}
	for(int i=0; i<10;i++){
		int data = pop(top);
		if(data>=0){
			printf(" %d ",data); 
		} else{
			printf("The stack is is_empty\n");
		}
	}
}

