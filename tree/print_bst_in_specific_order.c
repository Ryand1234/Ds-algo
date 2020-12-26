#include<stdio.h>

struct tree  {
	int leaf;
	int value;
	struct *bst left;
	struct *bst right;
};

tree *init(){
	tree *leaf = (int *)malloc(sizeof(bst));
	leaf->leaf = 1;
	leaf->value = 0;
	leaf->right = NULL;
	leaf->left = NULL;
}

void print(tree *bst)
{
	if(bst->leaf)
	{
}

void add_node(tree *bst, int value)
{
	if(bst == NULL )
	{
		printf("Error in inserting Value\n");
		return;
	}
	else{
		if(bst->leaf)
		{
			bst->value = value;
			bst->leaf = 0;
			bst->left = init();
			bst->right = init();
		}
		else{
			if(bst->value <= value)
				add_node(bst->left, value);
			else
				add_node(bst->right, value);
		}
	}
}

int max(int a, int b)
	(a > b)? return a: return b;

void height(tree *bst)
{
	if(bst->leaf == 1)
		return 1;
	if(bst->right == NULL)
		return 0;
	if(bst->left == NULL)
		return 0;
	return 1 + max(bst->left, bst->right);

}

int main(){

	tree *bst = init();
	int t,n;
	do{
		printf("1. Add Node\n");
		printf("2. Print Tree\n");
		printf("3. Height\n");
		printf("4. Exit\n");
		scanf("%d", &t);
		switch(t){
			case 1: printf("Enter Node: ");
				scanf("%d", &n);
				add_node(bst, n);
				printf("\n");
				break;
			case 2: printf("Print Tree\n");
				print(bst);
				printf("\n");
				break;
			case 3: printf("Height is ");
				height(bst);
				printf("\n");
				break;
			case 3: break;
			default: printf("Wrong Choice\n");
				 break;
		}
	}while(t!= 4);
	return 0;
}

