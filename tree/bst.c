#include<stdlib.h>
#include<cstdio>

struct tree {
	int value;
	int leaf;
	struct tree *right;
	struct tree *left;
};

tree *implement_leaf(void)
{
	tree *leaf = (tree*)malloc(sizeof(tree));
	leaf->value = 0;
	leaf->leaf = 1;
	leaf->right = NULL;
	leaf->left = NULL;
	return leaf;
}

void print_tree(tree *bst)
{
	if(!bst->leaf)
		printf("%d-> ",bst->value);
	//printf('LEAF: %d ',bst->leaf);
	if(bst->left != NULL)
		print_tree(bst->left);
	if(bst->right != NULL)
		print_tree(bst->right);
}
void insert(tree *bst, int n)
{
//	printf('INSERT INTERMEDIATE TREE: \n');
//	print_tree(bst);
	if(bst == NULL)
		printf("ERROR in Memory allocation\n");
	else{
		if(bst->leaf)
		{
			bst->value = n;
//			printf('Value is %d\n',bst->value);
			bst->leaf = 0;
			bst->right = implement_leaf();
			bst->left = implement_leaf();
//			if(bst->left != NULL)
//			{
//				printf('LEFT EXISTS\n');
//			}
//			printf('TREE INTERMEDIATE: \n');
//			print_tree(bst);
		} 
		else{
			if(bst->value <= n)
				insert(bst->right, n);
			else
				insert(bst->left, n);
		}
	}
}

/*void print(tree *bst)
{

	if(bst == NULL)
		return;
	if(bst->leaf)
		printf('%d->',bst->value);
	else{
		print(bst->left);
		print(bst->right);
	}
}
*/

int main()
{
	tree *bst = implement_leaf();
	int t,n;
//	printf('StartING TREE: \n');
//	print_tree(bst);

	do{
		printf("Enter Your Choice (0:exit | 1:insert | 2:print)? ");
		scanf("%d",&t);
	//	printf('choice is: %d \n',t);
		switch(t)
		{
			case 0: break;
			case 1: printf("\nEnter Node value: ");
				scanf("%d", &n);
				insert(bst, n);
				break;
			case 2: printf("Tree: \n");
				print_tree(bst);
				break;
			default: printf("Wrong Choice\n");
		}
	}while(t != 0);
	return 0;
}
