#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct Node{
	int data;
	struct Node *next;
} Node;

Node *head = NULL;
Node *current=NULL;

void sortedInsert(int data){
	if(head==NULL){
		head= malloc(sizeof(Node));
		head->next=NULL;
		head->data=data;
	}
	current=malloc(sizeof(Node));
	current = head;
	/*while(current->next!= NULL && current->next->data < data){
		current=current->next;
	}*/
	Node *temp = malloc(sizeof(Node));
	 
}
void insert(int data){
		//current=NULL;
		Node *temp=NULL;
		if(head==NULL){
			head = malloc(sizeof(Node));
			head->next = NULL;
			head->data=data;
		} else{
			current = malloc(sizeof(Node));
			current = head;
			while(current->next!=NULL){
				if(current->data <data){
					temp=malloc(sizeof(Node));
					temp->data = data;
					temp->next=head;
					head = temp;
				}
				current=current->next;
			}
			if(current->data <data){
					temp=malloc(sizeof(Node));
					temp->data = data;
					temp->next=head;
					head = temp;
			} 
			current->next=malloc(sizeof(Node));
			current->next->data = data;
			current->next->next=NULL;

			/*if(current->data > data){
				printf("DEBUG: current->data: %d, data: %d\n",current->data, data);
				temp = malloc(sizeof(Node));
				temp->data = data;
				temp->next=head;
				head= temp;
			}else {
			//current=head;	
			current->next=malloc(sizeof(Node));
			current->next->data = data;
			current->next->next=NULL;*/
		//} 
	}
	/*Node *temp=(struct Node*)malloc(sizeof(Node));
	current = ( struct Node *) malloc(sizeof(Node));
	if(head==NULL || head->data <data){
		//printf("Debug\n");
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
	}*/
	// Node *temp = malloc(sizeof(Node *));
	// current = ( struct Node *) malloc(sizeof(Node));
	// if(head==NULL){
	// 	head = current;
	// } else {
	// 	temp->next=current;
	// }
	// current->next = NULL;
	// current->data=data;
	// temp =current;
}

int search(int key){
	current = malloc(sizeof(Node));
	current = head;
	current = current->next;
	while(current!=NULL){
		if(current->data==key){
			printf("DEBUG: current->data: %d\n", current->data);
			return 1;
		}
		else{
		//printf("DEBUG1 current->data: %d\n", current->data);
		current=current->next;
		//printf("DEBUG2 current->data: %d\n", current->data);
		//printf("DEBUG3 current->-next->data: %d\n", current->next->data);
		}
	} return 0;
}
int extract(int key){
	current=head;
	current = current->next;
	int flag =0;
	printf("Debug\n");
	while(current!=NULL){
		
		current->next->next;
		if(current->next->data==key){

			current->next = current->next->next;
			flag =0;
		}
		else{
		//printf("current->data: %d\n", current->data);
		//current=current->next;
		}
	} return flag;
}

void printList(){
	current=head;
	while(current!=NULL){
		printf("current->data: %d\n", current->data);
		current=current->next;
	}

}

int main(){
	//Node *head=NULL;
	int i, random_num;
	srand(time(NULL));
	for(i=0;i<10; i++){
		random_num = rand() % 99 +1;
		//printf("%d ", random_num);
		sortedInsert(i);
	}
	//printf("DEBUG: \n", head->next);
	printf("Pre Extract\n" );
	printList();
	int target =3;
	int check = extract(target); /*search(target);*/
	//int check = search(target);
	if(check==1){
		printf("Value: %d found\n", target);
	} else{
		printf("Value: %d not found\n", target);
	}
	printf("Post Extract\n");
	printList();
	return 0;


}

