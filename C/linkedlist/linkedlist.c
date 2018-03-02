#include<stdio.h>
#include<stdlib.h>


typedef struct node {
 int data;
 struct node *next;

}node ;
//node *head = NULL;
//node *current = NULL;


void printList(node *head){
	node *list = head;
	printf("\n[ ");

	while(list!=NULL){
	printf("%d ", list->data);
	list=list->next;
	}
	printf(" ]");
}

void insert(node *head,int data){
	node *current=head;//(node *)malloc(sizeof(node));
	while(current->next!=NULL){
		current = current->next;
	}
	current->next= malloc(sizeof(node));
	current->next->data=data;
	current->next->next=NULL;
	/*node *temp = (node *)malloc(sizeof(node));
	temp->data=data;
	//temp->next=head; // point it to the old node
	temp->next=head;
	head=temp; //pointhead to the the node in the list
	*/
}




int main(void){
	node *head=NULL;
	int i;
	for(i=0; i<10; i++)
		insert(head,i);

	printList(head);

return 0;
}
