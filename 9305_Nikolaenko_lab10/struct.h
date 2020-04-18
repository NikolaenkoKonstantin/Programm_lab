#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED

typedef struct fut{
    char *name;
    char *country;
    float probability;
    float statistics[2];
}fut;


typedef struct node{
    size_t id;
    fut *baza;
    struct node *next;
}node;


typedef struct head{
    size_t N;
    node *first;
    node *last;
}head;

#endif // STRUCT_H_INCLUDED
