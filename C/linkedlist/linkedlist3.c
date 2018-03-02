#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *next;
} node;

struct node *head=NULL;
struct node *prev;
struct node *current =NULL;
void insert(int data){
	current = (struct node *)malloc(sizeof(node));
	if(head==NULL)
		head=current;
	else {
		prev->next=current;
	}
	current->data=data;
	current->next=NULL;
	prev = current;
}

void printList(){
	current = head;
	printf("[");
	while(current!=NULL){
		printf(" %d ", current->data);
		current = current->next;
	}
	printf("]\n");

}

int main(){

	int i;
	for(i=0;i<10;i++){
		insert(i);
	}
	printList();
}
