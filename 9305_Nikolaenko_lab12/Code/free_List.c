#include "h_files/free_List.h"

void free_head(head *q){
    free_node(q -> first);
    q -> first = NULL;
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

    while((temp -> next) != (q -> first)){
        node *p = NULL;
        p = temp;
        temp = temp -> next;
        free_node(p);
    }

    free(q);
    free_node(temp);
}
