#include <stdio.h>
#include "struct.h"
#include <stdlib.h>
#include "option_With_List.h"
#include "split.h"
#define max 200
#ifndef IO_H_INCLUDED
#define IO_H_INCLUDED

void inform();

void *output_node(node *temp);

void output_list(head *q);

void output_list_reverse(head *q);

void enterFromKeyboard(head *q);

void fill_list(head *q);

#endif // IO_H_INCLUDED
