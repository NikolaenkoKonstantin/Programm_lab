#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED
#include <stdlib.h>

#ifdef linux
#define CLS system("clear")
#else
#define CLS system("cls")
#endif

typedef struct fut
{
    char *name; /*name club*/
    char *country; /*name country*/
    float probability; /*probability of getting into the Champions League*/
    float statistics[2]; /*[0] - count wins, [1] - count draws */
} fut;


typedef struct node
{
    int id;
    fut *baza;
    struct node *prev;
    struct node *next;
} node;


typedef struct head
{
    int N;
    struct node *first;
    struct node *last;
} head;

#endif // STRUCT_H_INCLUDED
