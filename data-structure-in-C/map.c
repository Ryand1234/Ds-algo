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

int main()
{
	int t;
	Map *map = init();
	map->key = 5;
	map->value = 6;
	map->index = init();
	map->index->key = 8;
	map->index->value = 9;
	map->index->index = init();
	keys(map);
}
