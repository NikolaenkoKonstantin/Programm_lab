#ifndef OPTION_WITH_RINGLIST_H_INCLUDED
#define OPTION_WITH_RINGLIST_H_INCLUDED
#include <stdlib.h>
#include "struct.h"
#include "free_List.h"
#include <malloc.h>

void malloc_node(node *temp);

head *create_head();

node *create_node(head *q);

void add_last(head *q);

void delete_node(node *p, head *q);

void delete_by_number(head *q);

#endif // OPTION_WITH_RINGLIST_H_INCLUDED
