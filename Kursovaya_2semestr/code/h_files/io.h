#include <stdio.h>
#include "struct.h"
#include <stdlib.h>
#include "option.h"
#include "search.h"
#include "sort.h"
#include "struct.h"
#include "edit.h"
#define max 200
#ifndef IO_H_INCLUDED
#define IO_H_INCLUDED

void title();

void menu(head *q);

int charToInt(char numeric);

void split(char *mes, head *q);

void delay();

int input(char *s1);

void spravka();

void save_data(head *q);

void inform();

void *output_node(node *temp, int i);

void output_list(head *q);

void output_list_reverse(head *q);

void enterFromKeyboard(head *q);

void fill_list(head *q);

#endif // IO_H_INCLUDED
