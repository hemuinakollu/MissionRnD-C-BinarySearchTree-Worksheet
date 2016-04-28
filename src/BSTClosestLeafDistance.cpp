/*
Given a Binary Search Tree and a Node(temp).Find the Closest Distance from the Node to 
any leaf of the Tree.
(Least number of Edges needed to be travelled to go to the Node )

Ex : Consider the below tree .
      2
     / \
,   1   3
         \
         14
For 3 ,Output is 1 . As its closest leaf is 14 and 3 is at a distance of 1 to 14 .

Ex 2: Consider the below tree .
    2
   / \
  1   3
       \
        14
        / \
       9   20
      /      \
     6       25
For 3 ,Output is now 2 . As closest leaf to 3 is 1 and 3 is at a distance of 2 to 1 .
(through root 2 )

For 14 ,O/P : 2
For 2 , O/P : 1

Return -1 ,for Invalid Inputs
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
  struct node * left;
  int data;
  struct node *right;
};

int min_2(int a, int b)
{
	if (a < b)
		return a;
	else
		return b;
}


int Down_leaf(struct node *root)
{
	
	if (root == NULL)
		return INT_MAX;
	if (root->left == NULL && root->right == NULL)
		return 0;

	
	return 1 + min_2(Down_leaf(root->left), Down_leaf(root->right));
}


int closest_leaf(struct node *root, int k, struct node *b[],
	int i)
{
	
	if (root == NULL)
		return INT_MAX;

	
	if (root->data== k)
	{
		
		int r = Down_leaf(root);

		
		for (int j = i - 1; j >= 0; j--)
			r = min_2(r, i - j + Down_leaf(b[j]));
		return r;
	}

	
	b[i] = root;
	return min_2(closest_leaf(root->left, k, b, i + 1), closest_leaf(root->right, k, b, i + 1));

}



int get_closest_leaf_distance(struct node *root, struct node *temp)
{
	if (root == NULL || temp == NULL)
		return -1;
	else
	{
		struct node *b[1000];

		return closest_leaf(root, temp->data, b, 0);
	}
}