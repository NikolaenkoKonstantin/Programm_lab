#include <stdlib.h>
#include "struct.h"
#include "free_list.h"
#ifndef SPISOK_OPTION_H_INCLUDED
#define SPISOK_OPTION_H_INCLUDED

void arithmetic_mean(head *q);

head *create_head();

node *create_node(head *q);

void add_last(head *q);

void delete_first(head *q);

#endif // SPISOK_OPTION_H_INCLUDED
