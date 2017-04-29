#include "list.h"

int main()
{
	list_t *ahead = NULL;
	ahead = list_insert_last(ahead,  10);
	ahead = list_insert_last(ahead,  11);
	ahead = list_insert_last(ahead,  12);
	ahead = list_insert_last(ahead,  13);
	list_display(ahead);
	return 0;
}


