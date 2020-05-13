#include "free_list.h"

//Cleansing the head
void free_head(head *q){
    free_node(q -> first);
    q -> first = NULL;
    q -> last = NULL;
    free(q);
}


//Clearing a node
void free_node(node *temp){
    if((temp -> next) != NULL) temp -> next = NULL;
    free(temp);
}


//Cleansing of the list
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
