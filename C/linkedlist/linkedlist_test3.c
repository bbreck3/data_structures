#include<stdio.h>
#include<stdlib.h>



typedef struct Node{
	int data;
	struct Node *next;
} Node;

Node *head = NULL;
Node *current=NULL;

void insert( int data){
	Node *temp=(struct Node*)malloc(sizeof(Node));
	current = ( struct Node *) malloc(sizeof(Node));
	if(head==NULL || head->data <data){
		temp->next = head;
		head = temp;
	}else{
		current=head;
		while(current->next!=NULL && current->next->data <data){
			current = current->next;
		}
		temp->next=current->next;
		current->next=temp;
		temp->data=data;
	}
}

void printList(){
	//current = malloc(sizeof(Node));
	//printf("head->data %d\n", head->data);I
	current=head;
	
	current=current->next; //to fix bug...?
	while(current!=NULL){
		printf("%d, ", current->data);
		current=current->next;
	}
	//free(current);
}
int search(int key){
	//urrent = malloc(sizeof(Node));
	current = head;
	// printf("key: %d\n",key);
	// printf("current: %d\n", current->data);
	while(current!=NULL){
		int temp = current->data;
		//printf("temp: %d, ", temp);
		if(temp==key){
			return 1;
		} else{
			current= current->next;
			return 0;
		}
	}

}
int extract(int key){
	// Node *current = malloc(sizeof(Node));
	//Node *tempNode = malloc(sizeof(Node));
	current = head;
	while(current!=NULL){
		int tempInt = current->data;
		printf("%d\n",tempInt );
		if(tempInt==key){
				current= current->next;
				return 1;	
		} else{
			return 0;
		}
	}	

}

int main(){
	int num;
	//Node *head = malloc(sizeof(Node));
	//strut Node *prev;
	//struct Node *current=NULL;
	int i;
	for(i=10;i>=0; i--){
		num = rand() % 99 +1;
		insert(i);
		//insert(i);
	}
	printList();
	int target = 3;
	int check = search(target);

	//int check = extract(target);
	printf("\n");
	if(check==1){
		printf(" Val: %d found\n",target );
	}else{
		printf(" Val: %d not found\n",target );
	}
	printList();


}

