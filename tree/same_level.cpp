#include<iostream>
#include<map>
using namespace std;

struct Tree 
{
	int value;
	int leaf;
	struct Tree *left;
	struct Tree *right;
};

Tree *init()
{
	Tree *bst = (Tree*)malloc(sizeof(Tree));
	bst->value = 0;
	bst->leaf = 1;
	bst->left = NULL;
	bst->right = NULL;
	return bst;
}

void insert(Tree *bst, int n)
{
	if(bst == NULL)
		printf("Error in inserting");
	else
	{
		if(bst->leaf)
		{
			bst->value = n;
			bst->leaf = 0;
			bst->right = init();
			bst->left = init();
		}
		else
		{
			if(bst->value < n)
				insert(bst->right, n);
			else
				insert(bst->left, n);
		}
	}
}

int max(int a, int b)
{
	if( a > b )
		return a;

	return b;
}

int height(Tree *bst)
{
	if(bst->left == NULL)
		return 0;
	
	if(bst->right == NULL)
		return 0;

	if(bst->leaf)
		return 1;

	return 1 + max(height(bst->left), height(bst->right));
}

void print(Tree *bst)
{
	if(!bst->leaf)
		printf("%d->", bst->value);

	if(bst->left != NULL)
		print(bst->left);
	
	if(bst->right != NULL)
		print(bst->right);
}

Tree *print_next(Tree *bst, int n, int &node, int level = 1)
{
	if(bst->leaf)
		return NULL;

	if(bst->value == n)
	{
		node = level;
	}
	else
	{
		if((node > 0)&&(!bst->leaf))
		{
			if(node == level)
			{	
				return bst;
			}
		}
	}

	Tree *t = print_next(bst->left, n, node, level + 1);

	if(t != NULL)
		return t;

	return print_next(bst->right, n, node, level + 1);
}

int main()
{
	Tree *bst = init();
	insert(bst, 5);
	insert(bst, 10);
	insert(bst, 2);
	insert(bst, 1);
	insert(bst, 3);
	insert(bst, 8);
	insert(bst, 6);
	insert(bst, 9);
	insert(bst, 13);
	print(bst);
	printf("\nHeight is %d\n",height(bst));
	int level = 0;
	
	Tree *ans = print_next(bst, 2, level);
	if(ans != NULL)
		printf("Next element is %d\n",ans->value);
	else
		printf("Node doenst exist");
	
	level = 0;
	Tree *ans1 = print_next(bst, 8, level);
	
	if(ans != NULL)
                printf("Next element is %d\n",ans1->value);
        else
                printf("Node doenst exist");

	return 0;
}
