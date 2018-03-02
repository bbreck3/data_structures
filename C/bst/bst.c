#include<stdio.h>
#include<stdlib.h>

struct BstNode{
	int data;
	BstNode *left;
	BstNode *right;
} BstNode;

BstNode *root = NULL;

BstNode *getNewNode(int data){
	BstNode *newNode = (struct BstNode*)malloc(sizeof(BstNode));
	newNode->data=data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

bool search(BstNode *root, int data){
	if(root ==NULL) return false;
	else if(data <=root->data) return search(root->left,data);
	else return search(root->right,data);
}
void insert(Bst * root, int data){
	if(root==NULL){
		root = getNewNode(data);
	} else if(data <=root->data){
		root->left = Insert(root->left, data);
	}else if(data >= root->data){
		root->right = Insert(root->right, data);
	}

}
int main(){
//struct *root = (struct *)malloc(sizeof(Node));
	insert(root, 15);
	insert(root, 10);
	insert(root, 20);
}



