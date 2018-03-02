#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node *next;
} Node;
struct Node *top = NULL;

void push(int data){
	struct Node *temp = (struct Node *)malloc(sizeof(struct Node *));
	temp->data =data;
	temp->next=top;
	top = temp;
}

int isEmpty(struct Node *top){
	//return(top==NULL)
	if(top==NULL){
		return 1;
	}
		return 0;
}

int pop(){
	struct Node *temp;
	if(isEmpty(top))
		return -1;
	temp = top;
	int data = temp->data;
	top = top->next;
	free(temp);
	return data;
}

int main(){
	int i;
	for(i=0; i<10; i++){
		push(i);
	}
	for(i=0; i<10;i++){
		int data = pop();
		printf(" %d ",data); 
	}
	//int check=
}

