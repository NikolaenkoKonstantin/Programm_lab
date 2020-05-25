#ifndef SEARCH_H_INCLUDED
#define SEARCH_H_INCLUDED
#include "struct.h"
#include "option.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "search.h"
#include "io.h"
#define max 200

void delete_by_number(head *q);

node *delete_matches(head *q, node *temp, node *p);

void search_mega(head *q, char *s, int n, float b, float e, int f);

void input_name(head *q, int n);

void input_country(head *q, int n);

void input_probability(head *q, int n);

void input_wins(head *q, int n);

void input_draws(head *q, int n);

void choose(head *q, char *s, int n);

void search_match(head *q);

void deleteCards(head *q);

#endif // SEARCH_H_INCLUDED
