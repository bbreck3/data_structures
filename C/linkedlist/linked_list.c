#include<stdio.h>
#include<stdlib.h>
#include<time.h>


typedef struct Node{
	int data;
	struct Node *next;
} Node;

Node *insert( int data,Node *head){
	Node *temp=malloc(sizeof(Node));
	/*temp->data=data;
	temp->next=head;
	head=temp;*/
	Node *current = malloc(sizeof(Node));
	if(head==NULL || head->data <data){
		temp->next = head;
		head = temp;
		head->next=NULL;
	}else{
		current=head;
		while(current->next!=NULL && current->next->data <data){
			current = current->next;
		}
		temp->next=current->next;
		current->next=temp;
		temp->data=data;
	}
	return head;
}

void printList(Node *head){
	Node *current = malloc(sizeof(Node));
	current=head;
	current=current->next; //to fix bug...?
	while(current!=NULL){
		printf("current->data: %d\n", current->data);
		current=current->next;
	}
	free(current);
}
int search(int key, Node *head){
	Node *current=head;
	current=current->next;
	while(current!=NULL){
		int temp = current->data;
		if(temp == key){
			return 1;
		}else{
			current=current->next;
		}
	}
	free(current);
	return 0;
}
int extract(int key,Node *head){
	Node *current = malloc(sizeof(Node));
	current=head;
	int flag = 0;
	while(current!=NULL && current->next!=NULL){
		if(current->next->data==key){
			current->next = current->next->next;
			flag=1;
		}
		current = current->next;
	}
	free(current);
	return flag;
}

int size(Node *head){
	Node *current = malloc(sizeof(Node));
	current = head;
	current = current->next;
	int num_elems=0;
	while(current!=NULL){
		num_elems++;
		current=current->next;
	}
	free(current);
	return num_elems;
}
void free_memory(Node *head){
	Node *temp= head;
	while(head!=NULL){
		temp = head;
		head=head->next;
		free(temp);
	}
	free(head);
}

int main(){
	int num;
	Node *head = NULL;
	srand(time(NULL));
	int i;
	for(i=15;i>=0; i--){
		num = rand() % 99 +1;
		head =insert(num,head);
		//insert(i);
	}
	printList(head);
	int list_size = size(head);
	printf(" The list has %d elements\n", list_size);
	int target = 12;
	//int check = extract(target,head);
	int check = search(target,head);
	if(check==1){
		printf(" Val: %d found\n",target );
	}else{
		printf(" Val: %d not found\n",target );
	}
	//printList(head);
	free_memory(head);

}

