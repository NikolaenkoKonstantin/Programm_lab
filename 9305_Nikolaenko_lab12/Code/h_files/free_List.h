#ifndef FREE_LIST_H_INCLUDED
#define FREE_LIST_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

void free_head(head *q);

void free_node(node *temp);

void free_list(head *q);

#endif // FREE_LIST_H_INCLUDED
