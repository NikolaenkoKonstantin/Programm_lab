#ifndef SEARCH_H_INCLUDED
#define SEARCH_H_INCLUDED
#include "struct.h"
#include "option_With_List.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "split.h"
#include "delete_by_search.h"
#define max 200

void search_match_name(head *q);

void search_match_country(head *q);

void search_match_probability(head *q);

void search_match_wins(head *q);

void search_match_draws(head *q);

void search_match(head *q);

#endif // SEARCH_H_INCLUDED
