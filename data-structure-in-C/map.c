#include<cstdlib>
#include<cstdio>

struct Key {
	int k;
};

struct Value {
	int j;
};

struct Map {
	int key;
	int value;
	struct Map *index;
};

Map *init()
{
	Map *map = (Map*)malloc(sizeof(Map));
	map->value = 0;
	map->index = NULL;
	map->key = 0;
	return map;
}

void keys(Map *m)
{
	if(m->index == NULL)
		return;
	printf("%d->",m->key);
	keys(m->index);
}

void insert(Map *map, int key, int value)
{
	
	if(map->index == NULL)
	{
		map->key = key;
		map->value = value;
		map->index = init();
	}
	else {
		insert(map->index, key, value);
	}
}


void search(Map *map, int key)
{
//	printf('INIT Key: %d\n',map->key);
	if(map->key == key)
	{	printf("Value is %d\n",map->value);
		return;
	}
	else
	{
		if(map->index == NULL)
		{	
			printf("Key doesnt Exist");
			return;
		}
		else
			search(map->index, key);
	}
}



int main()
{
	int t,k,v;
	Map *map = init();
		
	do{
		printf("Enter Your Value: (0:Exit | 1:Insert | 2:Search)? ");
		scanf("%d",&t);
		switch(t)
		{
			case 0: break;
			case 1: printf("Key: ");
				scanf("%d",&k);
				printf("Value: ");
				scanf("%d",&v);
				insert(map, k, v);
				break;
			case 2: printf("Search Key: ");
				scanf("%d",&k);
				search(map, k);
				break;
			default: printf("Wrong Choice\n");
		}
	}while(t != 0);	

	return 0;
}
