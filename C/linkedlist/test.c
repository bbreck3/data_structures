#include<stdio.h>
#include<stdlib.h>


typedef struct LL{
	int data;
     LL *next;	
} LL;


void sortedInsert(LL **head , int X)
{
	LL*temp = *head ;
	LL *t = new LL;
	//if list is empty
	if(*head==NULL)
	{
		*head = new LL;
		(*head)->data = X;
		(*head)->next = NULL;
	}
	
	else
	{
		
		if(X < temp->data) //start node
		{
			t = new LL;
			t->data = X;
			t->next = *head;
			*head = t;
		}
			
		else
		{
			while(temp->next != NULL and !(X < temp->next->data && X >= temp->data)) //as it is sorted so X must lie between the consecutive values or else at end
				temp=temp->next;
			
			if(temp->next == NULL) //X will go to end
			{
				temp->next = new LL;
				temp = temp->next;
				temp->data = X;
				temp->next = NULL;
			}
			else //X is inserted in between some nodes in list
			{
				t = new LL;
				t->data = X;
				t->next = temp->next; //make the new node's next as the next of current node because the 't' node will lie between consecutive nodes
				temp->next = t;
			}
		}
	}
}

void display(LL **head)
{
	LL *temp=*head;
	while(temp!=NULL)
		{
			if(temp->next!=NULL)
			printf("%d ",temp->data);
			else
			printf("%d ",temp->data);
			
			temp=temp->next; //move to next node
		}
		//O(number of nodes)
}


int main()
{
	
	LL *head = NULL; //initial list has no elements
	printf("\nCurrent List is :-\n");
	display(&head);
	sortedInsert(&head,6);
	printf("\nCurrent List is :-\n");
	display(&head);
	sortedInsert(&head,16);
	printf("\nCurrent List is :-\n");
	display(&head);
	sortedInsert(&head,15);
	printf("\nCurrent List is :-\n");
	display(&head);
	sortedInsert(&head,50);
	printf("\nCurrent List is :-\n");
	display(&head);
	sortedInsert(&head,1);
	printf("\nCurrent List is :-\n");
	display(&head);
	sortedInsert(&head,23);
	printf("\nCurrent List is :-\n");
	display(&head);
	
	
	return 0;
}