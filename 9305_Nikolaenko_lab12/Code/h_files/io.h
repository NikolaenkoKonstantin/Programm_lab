#ifndef IO_H_INCLUDED
#define IO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "option_With_RingList.h"
#include "split.h"
#define max 200

void inform();

void *output_node(node *temp);

void output_list(head *q);

void enterFromKeyboard(head *q);

void fill_list(head *q);

#endif // IO_H_INCLUDED
