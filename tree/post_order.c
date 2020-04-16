#include<stdlib.h>
#include<cstdio>

struct tree {
	int value;
	int leaf;
	struct tree *right;
	struct tree *left;
};

tree *implement_leaf()
{
	tree *leaf = (tree*)malloc(sizeof(tree));
	leaf->value = 0;
	leaf->leaf = 1;
	leaf->right = NULL;
	leaf->left = NULL;
	return leaf;
}

void insert(tree *bst, int n)
{
	if(bst == NULL)
		printf("Error in inserting value\n");
	else{
		if(bst->leaf)
		{
			bst->value = n;
			bst->leaf = 0;
			bst->right = implement_leaf();
			bst->left = implement_leaf();
		} else {
			if(bst->value <= n)
				insert(bst->right, n);
			else
				insert(bst->left, n);
		}
	}
}

void post_print(tree *bst)
{

	if(bst->left != NULL)
		post_print(bst->left);

	if(bst->right != NULL)
		post_print(bst->right);

	if(!bst->leaf)
		printf("%d->",bst->value);
}


int max(int a, int b)
{
	if(a > b)
		return a;

	return b;
}
int height(tree *bst)
{
	
	if(bst->left == NULL)
		return 0;
	
	if(bst->right == NULL)
		return 0;

	if(bst->leaf)
		return 1;
	
	return 1 + max(height(bst->left),height(bst->right));

}

int main()
{

	tree *bst = implement_leaf();
	int n,t;
	do{
		printf("\nEnter Your Choice: (0:exit | 1:insert | 2:print | 3:height)? ");
		scanf("%d",&t);
		switch(t)
		{
			case 0:break;
			case 1: printf("Enter node value: ");
				scanf("%d",&n);
				insert(bst, n);
				break;
			case 2: printf("TREE: \n");
				post_print(bst);
				break;
			case 3: n = height(bst);
				printf("height: %d",n);
				break;
			default: printf("Wrong Choice\n");
		}
	}while(t != 0);
	return 0;
}
