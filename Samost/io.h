#ifndef IO_H_INCLUDED
#define IO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "spisok_option.h"
#include "split.h"
#define max 200

void output_node(node *temp);

void output_list(head *q);

void enterFromKeyboard(head *q);

void save_data(head *q, FILE *fileread);

void fill_list(head *q);
#endif // IO_H_INCLUDED
