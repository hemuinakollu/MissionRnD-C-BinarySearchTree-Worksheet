/*

Given a Binary Search Tree ,with two misplaced Node .Find those nodes and fix them .

Do not create a new tree ,Modify the original tree
Ex : In the below tree 3 and 30 is misplaced .

  5
 / \
2   3
 \
  30
When fixed 30 will be right node of 5 , and 3 will be right node of 2 .

Ex :In the below tree 1 and 20 are misplaced

         9
        / \
       4   1
      /     \
    20      30
Nodes 1 and 20 need to be fixed here .

*/
#include <stdio.h>
#include <stdlib.h>


struct node{
	struct node * left;
	int data;
	struct node *right;
};

struct node *temp[2] = { (struct node*)malloc(sizeof(struct node)), (struct node*)malloc(sizeof(struct node)) };

void fix_bst1(struct node* root, int *j, int s1, int s2)
{
	if (root == NULL)
		return;
	else if (root->data == s1 || root->data == s2)
	{
		temp[*j] = root;
		
		(*j)++;
		
		if (*j == 2)
		{
			
			temp[0]->data = temp[0]->data + temp[1]->data;
			temp[1]->data = temp[0]->data - temp[1]->data;
			temp[0]->data = temp[0]->data - temp[1]->data;
		}
	}
	
		fix_bst1(root->left, j, s1, s2);
		fix_bst1(root->right, j, s1, s2);
	
}
void ino1(struct node *root, int *arr, int *i)
{
	if (root != NULL)
	{
		ino1(root->left, arr, i);
		arr[*i] = root->data;
		(*i)++;
		ino1(root->right, arr, i);
	}
	else
		return;

}

void fix_bst(struct node *root){
	if (root == NULL)
		return;
	else
	{
		int k = 0;
		int *arr = (int*)malloc(1000);
		ino1(root, arr, &k);
		int s1 = 0, s2 = 0, flag = 0, index = 0;
		for (int i = 0; i < k - 1; i++)
		{
			if (arr[i]>arr[i + 1] && flag == 0)
			{
				s1 = arr[i];
				index = i;
				flag++;
			}
			else if (arr[i] > arr[i + 1] && flag == 1)
			{
				s2 = arr[i + 1];
				flag++;
			}
		}

		if (flag == 0)
		{
			return;
		}
		else if (flag == 1)
		{
			s2 = arr[index + 1];
		}
		int f = 0;
		fix_bst1(root, &f, s1, s2);



	}
}
