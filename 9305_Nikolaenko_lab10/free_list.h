#ifndef FREE_LIST_H_INCLUDED
#define FREE_LIST_H_INCLUDED
#include "struct.h"

void free_head(head *q){
    free_node(q -> first);
    q -> first = NULL;
    q -> last = NULL;
    free(q);
}


void free_node(node *temp){
    if((temp -> next) != NULL) temp -> next = NULL;
    free(temp -> baza -> name);
    free(temp -> baza -> country);
    free(temp -> baza);
    free(temp);
}


void free_list(head *q){
    node *temp = NULL;

    temp = q -> first -> next;

    free_head(q);

    while((temp -> next) != NULL){
        node *p = NULL;
        p = temp;
        temp = temp -> next;
        free_node(p);
    }

    free_node(temp);
}

#endif // FREE_LIST_H_INCLUDED
