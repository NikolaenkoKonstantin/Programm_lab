#include <stdio.h>
#include "struct.h"
#include <stdlib.h>
#include "option_With_List.h"
#include "split.h"
#include "command_selecting.h"
#define max 200
#ifndef IO_H_INCLUDED
#define IO_H_INCLUDED

void spravka();

void save_data(head *q, FILE *fileread);

void inform();

void *output_node(node *temp, int i);

void output_list(head *q);

void output_list_reverse(head *q);

void enterFromKeyboard(head *q);

void fill_list(head *q);

#endif // IO_H_INCLUDED
