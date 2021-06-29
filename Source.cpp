// Binary search tree - Implementation in C
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
};

struct Node* Insert(struct Node*, int);
struct Node* GetNewNode(int);
void inorder_recursive(struct Node *);

int main()
{
	struct Node *root = NULL;		// pointer to root node. Setting Tree as Empty.
	root = Insert(root, 15);
	root = Insert(root, 10);
	root = Insert(root, 20);
	root = Insert(root, 25);
	root = Insert(root, 8);
	root = Insert(root, 12);

	printf("\nInorder Traversal : \n");
	inorder_recursive(root);
	_getch();
}

struct Node* GetNewNode(int value)
{
	struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
	newnode->data = value;
	newnode->left = newnode->right = NULL;
	return newnode;
};

struct Node* Insert(struct Node *root, int value)
{
	if (root == NULL)		// empty tree
		root = GetNewNode(value);

	else if (value <= root->data)
		root->left = Insert(root->left, value);
	
	else
		root->right = Insert(root->right, value);

	return root;
}

void inorder_recursive(struct Node *root)
{
	if (root == NULL)
		return;
	else
	{
		inorder_recursive(root->left);
		printf("%d ", root->data);
		inorder_recursive(root->right);
	}
}