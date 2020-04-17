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

void bottom_check(Tree *bst, auto &map, int level = 0, int dist = 0)
{
	if(bst == NULL)
		return;

	if((level >= map[dist].second)&&(!bst->leaf))
	{
		map[dist].first = bst->value;
		map[dist].second = level;
		printf("VALUE: %d\n",map[dist].first);		
	}

	bottom_check(bst->left, map, level + 1, dist - 1);

	bottom_check(bst->right, map, level + 1, dist + 1);
}


void print_bottom(Tree *bst)
{
	map<int, pair<int, int>> map;

	bottom_check(bst, map);

	for(auto it: map)
	{
		printf("%d->",it.second.first);
	}

	printf("\n");
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
	print_bottom(bst);
	return 0;
}
