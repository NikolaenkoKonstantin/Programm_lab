#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED

typedef struct node{
    int id;
    int znach;
    struct node *next;
}node;


typedef struct head{
    int N;
    node *first;
    node *last;
}head;

#endif // STRUCT_H_INCLUDED
