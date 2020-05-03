#include "h_files/option_With_RingList.h"

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
    }

    return p;
}


node *create_node(head *q){
    node *temp;

    temp = malloc(sizeof(node));
    malloc_node(temp);

    temp -> next = temp;
    temp -> id = q -> N + 1;

    q -> N += 1;
    q -> first = temp;

    return temp;
}


void add_last(head *q){
    node *temp = NULL;

    temp = malloc(sizeof(node));
    malloc_node(temp);

    temp -> next = q -> first -> next;
    temp -> id = ((q -> N) + 1);
    q -> first -> next = temp;

    q -> first = temp;
    q -> N += 1;
}


void delete_node(node *p, head *q){
    node *temp = NULL;

    temp = p -> next;
    q -> N -= 1;

    if(temp != (q -> first)) p -> next = (temp -> next);
    else {
        p -> next = temp -> next;
        q -> first = p;
    }

    free_node(temp);
}


void delete_by_number(head *q){
    node *p = NULL;
    int k, i = 2;

    printf("\nEnter the cell number you want to delete:");
    scanf("%d", &k);

    p = q -> first;

    while(i < k){
        p = p -> next;
        ++i;
    }

    delete_node(p, q);
}
