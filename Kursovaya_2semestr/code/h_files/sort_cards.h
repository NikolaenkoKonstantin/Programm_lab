#ifndef SORT_CARDS_H_INCLUDED
#define SORT_CARDS_H_INCLUDED
#include <stdlib.h>
#include "struct.h"
#include "io.h"
#include "option_With_List.h"
#include "split.h"

void sort_names(head *q);

void sort_country(head *q);

void sort_probability(head *q);

void sort_wins(head *q);

void sort_draws(head *q);

void sort_cards(head *q);

#endif // SORT_CARDS_H_INCLUDED