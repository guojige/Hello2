#include "list.h"

int main()
{
	list_t *ahead = NULL;
	list_t *bhead = NULL;
	//list_display(ahead);
	//list_display(bhead);
	// list_insert(ahead, 5);  // error
	//
	printf("ahead list\n");
	ahead = list_insert(ahead, 5);
	ahead = list_insert(ahead, 7);
	ahead = list_insert(ahead, 9);
	ahead = list_insert(ahead, 2);
	//printf("%p\n", ahead);
	list_display(ahead);
	printf("bhead list\n");
	bhead = list_insert_last(bhead, 55);
	bhead = list_insert_last(bhead, 77);
	bhead = list_insert_last(bhead, 99);
	bhead = list_insert_last(bhead, 22);
	list_display(bhead);
	printf("delete...\n");
	bhead = list_delete(bhead, 55);
	bhead = list_delete(bhead, 22);
	list_display(bhead);
	
	return 0;
}


