#ifndef SPLIT_H_INCLUDED
#define SPLIT_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "option_With_RingList.h"

int str_len(char *s);

int charToInt(char numeric);

void split(char *mes, head *q);

#endif // SPLIT_H_INCLUDED
