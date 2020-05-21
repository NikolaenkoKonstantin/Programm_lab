#ifndef OPTION_WITH_LIST_H_INCLUDED
#define OPTION_WITH_LIST_H_INCLUDED
#include "free_List.h"
#include "struct.h"
#include <malloc.h>
#include <stdlib.h>
#include "io.h"

void malloc_node(node *temp);

head *create_head();

node *create_node(head *q);

void add_last(head *q);

node *add_first(head *q);

void delete_first(head *q);

void delete_node(node *temp, head *q);

node *copy_node(node *p, node *temp);

void swap_node(node *p, node *temp, head *q);

void transfer_node(node *p, node *temp, head *q);

void copy_list(head *q1, head *q);

#endif // OPTION_WITH_LIST_H_INCLUDED
