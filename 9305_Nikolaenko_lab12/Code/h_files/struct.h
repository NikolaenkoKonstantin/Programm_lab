#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED
#include <stdlib.h>

typedef struct fut{
    char *name;
    char *country;
    float probability;
    float statistics[2];
}fut;


typedef struct node{
    int id;
    fut *baza;
    struct node *next;
}node;


typedef struct head{
    int N;
    struct node *first;
}head;

#endif // STRUCT_H_INCLUDED
