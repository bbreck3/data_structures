#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<time.h>

typedef struct Node {
	int data;
	struct Node *next;
} Node;


Node *push(int data, Node *top){
	Node *temp = malloc(sizeof(Node));
	Node *current=malloc(sizeof(Node));
	if(top==NULL){
		temp->next=top;
		top=temp;
		top->next=NULL;
	} else{
		current=top;
		temp->next = current->next;
		current->next=temp;
		temp->data=data;
	}
	/*temp->data =data;
	//printf("temp->data: %d\n",temp->data);
	temp->next=top;
	top = temp;*/

	return top;
}

int isEmpty(Node *top){
	//return(top==NULL)
	if(top==NULL){
		return 1;
	}
		return 0;
}

Node *pop(Node *current){
	Node *temp=malloc(sizeof(Node));
	if(isEmpty(current))
		return NULL;
	temp = current;
	//int data = temp->data;
	//printf("data: %d\n",data);
	temp = temp->next;
	//free(temp);
	return temp;
}
void print_stack(Node *top){
	Node *current=malloc(sizeof(Node));
	current= top;
	current=current->next;
	while(current!=NULL){
		printf("%d ",current->data);
		current=pop(current);
	}
	/*printf("%d ",current->data);
		current=pop(current);*/
	//current=current->next;
	/*while(current!=NULL){
	printf("current->data %d", current->data);
	current=current->next;
	}*/
	//printf("current->data %d", current->data);
	
	/*while(current!=NULL){
		printf("current->data:%d ", current->data);
		current =current->next; //pop(current);
	}*/
	//printf("current->data:%d ", current->data);
	/*while(current!=NULL){
		current=pop(current);
		if(current!=NULL){
			printf(" %d\n",current->data); 
		} //current=current->next;
	}*/
}

int main(){
	int i,num;
	srand(time(NULL));
	Node *top = NULL;
	for(i=0; i<10; i++){
		num = rand() %99 +1;
		printf("%d ",num );
		top =push(num,top);
	}
	printf("\n");
	print_stack(top);
	//int check=
}

