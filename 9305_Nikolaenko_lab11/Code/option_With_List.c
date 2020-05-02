#include "h_files/option_With_List.h"

void malloc_node(node *temp){
    temp -> baza = malloc(sizeof(fut));
    temp -> baza -> name = malloc(30 * sizeof(char));
    temp -> baza -> country = malloc(30 * sizeof(char));
}


head *create_head(){
    head *p = NULL;

    p = malloc(sizeof(head));
    if(p){
        p -> N = 0;
        p -> first = NULL;
        p -> last = NULL;
    }

    return p;
}


node *create_node(head *q){
    node *temp;

    temp = malloc(sizeof(node));
    malloc_node(temp);

    temp -> prev = NULL;
    temp -> next = NULL;
    temp -> id = q -> N + 1;

    q -> N += 1;
    q -> first = temp;
    q -> last = temp;

    return temp;
}


void add_last(head *q){
    node *temp = NULL;

    temp = malloc(sizeof(node));
    malloc_node(temp);

    temp -> next = NULL;
    temp -> id = ((q -> N) + 1);
    temp -> prev = q -> last;

    q -> last -> next = temp;
    q -> last = temp;
    q -> N += 1;
}


node *add_first(head *q){
    node *temp;

    temp = malloc(sizeof(node));
    malloc_node(temp);

    temp -> prev = NULL;
    temp -> next = (q -> first);
    temp -> id = ((q -> N) + 1);

    q -> first -> prev = temp;
    q -> N += 1;
    q -> first = temp;

    return temp;
}


void delete_first(head *q){
    node *temp = NULL;

    temp = q -> first;

    q -> first = (temp -> next);
    q -> first -> prev = NULL;
    q -> N -= 1;

    if((q -> N) == 0) q -> last = NULL;

    free_node(temp);
}


void delete_node(node *temp, head *q){
    q -> N -= 1;
    temp = temp -> next;

    if((temp -> next) != NULL){
        temp -> next -> prev = temp -> prev;
        temp -> prev -> next = temp -> next;
    }
    else {
        q -> last = temp -> prev;
        q -> last -> next = NULL;
    }

    free_node(temp);
}
