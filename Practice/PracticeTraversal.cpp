#include <stdio.h>
#include <stdlib.h>

struct node {
    char data;
    struct node* left;
    struct node* right;
};

struct node* newNode(char data) {
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	
	return (node);
}

void printPostorder(struct node* node) {
	if (node == NULL){
		return;
	}
	printPostorder(node->left);
	printPostorder(node->right);
	printf("%c ", node->data);
}

void printInorder(struct node* node) {
	if (node == NULL){
		return;
	}
	printInorder(node->left);
	printf("%c ", node->data);
	printInorder(node->right);
}

void printPreorder(struct node* node) {
	if (node == NULL){
		return;
	}
	printf("%c ", node->data);
	printPreorder(node->left);
	printPreorder(node->right);
}

int main() {
	struct node *root = newNode('A');
	root->left = newNode('B');
	root->right = newNode('C');
	root->left->left = newNode('D');
	root->left->right = newNode('E');
	root->right->right = newNode('G');
	root->left->left->left = newNode('F');
	
	 printf("\nPreorder traversal of binary tree is \n");
	 printPreorder(root);
	
	 printf("\nInorder traversal of binary tree is \n");
	 printInorder(root);  
	
	 printf("\nPostorder traversal of binary tree is \n");
	 printPostorder(root);
	
	 getchar();
	 return 0;
}
