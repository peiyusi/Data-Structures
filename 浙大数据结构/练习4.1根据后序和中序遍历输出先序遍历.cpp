#include<bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
};

int search(int arr[], int start, int end, int value) {
	for (int i = start; i <= end; i++) {
		if (arr[i] == value) {
		    return i;
		}
	}
	return -1;
}

Node* newNode(int data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->left = node->right = NULL;
	return(node);
}

Node* buildUtil(int in[], int post[], int inStrt, int inEnd, int *pIndex) {
	if (inStrt > inEnd) {
		return NULL;
	}
	Node *node = newNode(post[*pIndex]);
	(*pIndex)--;
	if (inStrt == inEnd) {
		return node;
	}
	int iIndex = search(in, inStrt, inEnd, node->data);
	
	node->right = buildUtil(in, post, iIndex+1, inEnd, pIndex);
	node->left = buildUtil(in, post, inStrt, iIndex-1, pIndex);
	
	return node;
}

Node *buildTree(int in[], int post[], int n) {
	int pIndex = n-1;
	return buildUtil(in , post, 0, n-1, &pIndex);
}

void preOrder(Node* root){
    if(root==NULL)
        return;
    cout<<" "<<root->data;   
    preOrder(root->left);
    preOrder(root->right);
}
int main() {
	int N;
	scanf("%d", &N);
	int Post[N], In[N];
	for (int i = 0; i < N; i++) {
		scanf("%d", &Post[i]);
	}
	for (int j = 0; j < N; j++) {
		scanf("%d", &In[j]);
	}
	Node *root = buildTree(In, Post, N);
	printf("Preorder:");
	preOrder(root);
	return 0;
}

