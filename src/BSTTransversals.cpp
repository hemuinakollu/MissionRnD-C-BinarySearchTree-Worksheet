/*

Given a Binary Search Tree ,Calculate its Inorder ,Postorder and PreOrder

Input : A BST
Output : Copy Inorder/Postorder/Preorder into the array specified .

Note : Memory for the Array is already allocated ,Dont allocate it again using malloc
->Take help of helper functions which are actually solving the problem .
->Dont Process Invalid Inputs

Bonus Task :
->Go to the BSTTransversals Spec File ,We have left a custom test case for you ,Try to fill
it and understand how testing works .
*/

#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};


void ino(struct node *root, int *arr, int *i)
{
	if (root != NULL)
	{
		ino(root->left, arr, i);
		arr[*i] = root->data;
		(*i)++;
		ino(root->right, arr, i);
	}
	else
		return;

}
void inorder(struct node *root, int *arr){
	if (root == NULL || arr == NULL)
	{
		return;
	}
	int i = 0;
	ino(root, arr, &i);//passing &i as call by reference to update the i value


}
void preo(struct node *root, int *arr, int *i)
{
	if (root != NULL)
	{
		arr[*i] = root->data;
		(*i)++;
		preo(root->left, arr, i);
		preo(root->right, arr, i);
	}
	else
		return;

}
void preorder(struct node *root, int *arr){
	if (root == NULL || arr == NULL)
	{
		return;

	}
	int i = 0;
	preo(root, arr, &i);


}
void posto(struct node *root, int *arr, int *i)
{
	if (root != NULL)
	{
		posto(root->left, arr, i);
		posto(root->right, arr, i);
		arr[*i] = root->data;
		(*i)++;
	}
	else
		return;

}
void postorder(struct node *root, int *arr){
	if (root == NULL || arr == NULL)
	{
		return;
	}
	int  i = 0;
	posto(root, arr, &i);

}

