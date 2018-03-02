#include<stdio.h>
#include<stdlib.h>

struct node{
	int key;
	struct node *left, *right;
};

struct node *newNode(int item){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->key =item;
	temp->left=temp->right=NULL;

	return temp;
};
void inorder(struct node *root){
	if(root!=NULL){
		inorder(root->left);
		printf("%d\n",root->key );
		inorder(root->right);
	}
}

void preorder(struct node *root){
	if(root!=NULL){
		printf("%d\n",root->key );
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(struct node *root){
	if(root!=NULL){
		postorder(root->left);
		postorder(root->right);
		printf("%d\n",root->key );
	}
}
struct node *insert(struct node *node, int key){
	if(node==NULL){
		return newNode(key);
	} 
	if(key < node->key){
		node->left = insert(node->left,key);
	} else if(key > node->key){
		node->right = insert(node->right,key);
	}

	return node;
};

struct node *search(struct node * node, int key){
	//printf("%s\n","Debug" );
	if(node==NULL || node->key==key){
		return node;
	}
	else if(node->key < key){
		return search(node->right, key);
	}else if(node->key > key){
		return search(node->left, key);
	} else{
		//printf("%s\n","DEBUG" );
		//struct node *temp = (struct node *)malloc(sizeof(struct node));
		//temp->key=-1;
		//printf("%d\n Temp->key: ",temp->key );
		return NULL;
	}	
};

int main(int argc, char const *argv[])
{
	struct node *root =NULL;
	root = insert(root,50);
	insert(root,30);	
	insert(root,20);	
	insert(root,40);	
	insert(root,70);	
	insert(root,60);	
	insert(root,80);
	printf("%s\n", "inorder traversal:" );
	inorder(root);
	printf("\n");

	printf("%s\n", "preorder traversal:" );
	preorder(root);
	printf("\n");

	printf("%s\n", "postorder traversal:" );
	postorder(root);
	printf("\n");

	printf("%s\n", "Search: " );
	struct node *temp = search(root,30);
	//printf("%d\n Temp->Key",temp->key );
	if(temp!=NULL){
		printf("%s %d\n", "Key: ", temp->key);
	} else{
		printf("%s \n", "No Key Found");
		//printf("%s\n","Key: " );
		//printf("%d", temp->key);
	}
	return 0;
}
