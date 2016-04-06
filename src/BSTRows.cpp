/*
Given a Binary Search Tree ,Copy All Elements in BST into a Array in horizontal row by row fashion where
each row is copied from Right to Left.

First copy the Frist row ,Next the second row etc .
Ex : If Bst is 
    6                        <-- Copy this first 
   / \
  4  10                      <-- Copy this row next from 10 and next 4 ..
 / \   \
1   5   15                   <-- Order her is 15 ,5 ,1 
          \
          17

Output will be a array consisting of [6,10,4,15,5,1,17];

Input : BST head node ;
Output :Return An array which has All the elements in row by row order (R->L) .

Note : Return -1 for Invalid Cases .
*/

#include <stdlib.h>
#include <stdio.h>
#include<malloc.h>
struct node{
	struct node * left;
	int data;
	struct node *right;
};

int get_height1(struct node *root){

	int max = 0;
	if (root == NULL)
		return 0;
	else
	{
		int l = get_height1(root->left);
		int r = get_height1(root->right);

		if (l > r)
			max = l + 1;
		else
			max = r + 1;
		return max;
	}

}

void right_to_left(struct node* root, int l,int *j,int *a)
{
	if (root == NULL)
		return;
	if (l == 1)
	{
		a[*j] = root->data;
		(*j)++;
	}
	else if (l > 1)
	{
		right_to_left(root->right, l - 1,j,a);
		right_to_left(root->left, l - 1,j,a);
	}
}
int* BSTRighttoLeftRows(struct node* root)
{
	int *a=(int*)malloc(100);
	if (root == NULL)
		return NULL;
	else
	{
		int l = get_height1(root);
		int i;
		int j = 0;
		
		for (i = 1; i <= l; i++)
			right_to_left(root, i, &j, a);
		return a;
		
	}

   
}
