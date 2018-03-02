#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *next;
} Node;

struct Node *head = NULL;
struct Node *prev;
struct Node *current=NULL;
void insert(int data){
	current = ( struct Node *) malloc(sizeof(Node));
	if(head==NULL){
		head = current;
	} else {
		prev->next=current;
	}
	current->next = NULL;
	current->data=data;
	prev =current;
}

void printList(){
	current=head;
	while(current!=NULL){
		printf("current->data: %d\n", current->data);
		current=current->next;
	}

}

int main(){
	int i;
	for(i=0;i<10; i++){
		insert(i);
	}
	printList();


}

