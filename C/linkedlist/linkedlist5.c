#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
}node;

struct node *head=NULL;
struct node *prev, *current=NULL;

void insert(int data){
	current = (struct node *)malloc(sizeof(node));
	if(head==NULL){
		head = current;
	} else{
		prev->next=current;
	}
	current->next=NULL;
	current->data=data;
	prev = current;
}

void printList(){

	current = head;
	printf("[ ");
	while(current!=NULL){
		printf(" %d ", current->data);
		current= current->next;
	}
	printf(" ]");
}

int main(){
	int i;
	for(i=0;i<10;i++)
		insert(i);
	printList();
	
}
