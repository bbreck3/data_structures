#include<stdio.h>
#include<stdlib.h>

#define MAX 10

void create_bst(int arr[], int num, int index){
	if(index>=MAX){
		printf("\nNo more roomr");
	} else{
		if(arr[index]==-1){
			arr[index]=num;
		} else if(num<arr[index]){
			create_bst(arr,num,index*2);
		} else{
			create_bst(arr,num,(index*2)+1);
		}
	}

}

void inorder(int arr[], int index){
	printf("Debug\n");
	if(arr[index]!=-1){

		inorder(arr,index*2);
		printf("%d ", arr[index]);
		inorder(arr,(index*2)+1);
	}
}
void preorder(int arr[], int index){
	if(arr[index]!=-1){
		printf("%d ", arr[index]);
		inorder(arr,index*2);
		inorder(arr,(index*2)+1);
	}
}
void postorder(int arr[], int index){
	if(arr[index]!=-1){
		inorder(arr,index*2);
		inorder(arr,(index*2)+1);
		printf("%d ", arr[index]);
	}
}
int main(){
	int numbers[MAX];
	int num;
	for (int i = 0; i < MAX; ++i)
	{
		//num = rand() % MAX +1;
		numbers[i]=-1;
	}
	for (int i = 0; i < MAX; ++i)
	{
		num = rand() % MAX +1;
		create_bst(numbers,num,1);
	}

	inorder(numbers,1);
}
