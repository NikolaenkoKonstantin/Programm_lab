#ifndef OPTION_WITH_LIST_H_INCLUDED
#define OPTION_WITH_LIST_H_INCLUDED
#include "free_List.h"
#include "struct.h"
#include <malloc.h>
#include <stdlib.h>

void malloc_node(node *temp);

head *create_head();

node *create_node(head *q);

void add_last(head *q);

node *add_first(head *q);

void delete_first(head *q);

void delete_node(node *temp, head *q);

#endif // OPTION_WITH_LIST_H_INCLUDED
