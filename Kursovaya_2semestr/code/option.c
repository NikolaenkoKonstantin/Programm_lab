#include "h_files/option.h"

//checking for uniqueness
void check_on_repeat(node *temp, head *q){
    /*If the same element is found by the name of the club, it is immediately deleted*/
    node *temp1 = q -> first;
    int t = q -> N,
        key = 0;

    for(int i = 0; i < t; i++){
        if(temp1 != temp)
            if(strcmp(temp -> baza -> name, temp1 -> baza -> name) == 0){
                    key = 1;
                    i = t;
            }
        temp1 = temp1 -> next;
    }

    if(key == 1){
        if(temp == q -> first) delete_first(q);
        else delete_node(temp -> prev, q);
        printf("\nThis command already exists in the file system");
    }
}


//cleaning the head
void free_head(head *q)
{
    free_node(q -> first);
    q -> first = NULL;
    q -> last = NULL;
    free(q);
}


//clearing a node
void free_node(node *temp)
{
    if((temp -> next) != NULL) temp -> next = NULL;

    if((temp -> prev) != NULL) temp -> prev = NULL;

    free(temp -> baza -> name);
    free(temp -> baza -> country);
    free(temp -> baza);
    free(temp);
}


//clearing the list
void free_list(head *q)
{
    node *temp = NULL;
    temp = q -> first -> next;

    free_head(q);

    while((temp -> next) != NULL)
    {
        node *p = NULL;
        p = temp;
        temp = temp -> next;
        free_node(p);
    }

    free_node(temp);
}


//allocating memory for the entire node
void malloc_node(node *temp)
{
    temp -> baza = malloc(sizeof(fut));
    temp -> baza -> name = malloc(30 * sizeof(char));
    temp -> baza -> country = malloc(30 * sizeof(char));
}


//the creation of the head
head *create_head()
{
    head *p = NULL;

    p = malloc(sizeof(head));
    if(p)
    {
        p -> N = 0;
        p -> first = NULL;
        p -> last = NULL;
    }

    return p;
}


//creating the first node
node *create_node(head *q)
{
    node *temp;
    temp = malloc(sizeof(node));
    malloc_node(temp);

    temp -> prev = NULL;
    temp -> next = NULL;
    temp -> id = q -> N + 1;

    if(q -> N == 0)
    {
        q -> first = temp;
        q -> last = temp;
    }

    q -> N += 1;

    return temp;
}


//adding a node to the end
void add_last(head *q)
{
    node *temp = create_node(q);

    temp -> prev = q -> last;
    q -> last -> next = temp;
    q -> last = temp;
}


//adding a node to the beginning
node *add_first(head *q)
{
    node *temp = create_node(q);

    temp -> next = (q -> first);
    q -> first -> prev = temp;
    q -> first = temp;

    return temp;
}


//deleting the first node
void delete_first(head *q)
{
    node *temp = q -> first;

    if(temp -> next != NULL){
        q -> first = temp -> next;
        temp -> next -> prev = NULL;
    }

    q -> N -= 1;

    if((q -> N) == 0) q -> last = NULL;

    free_node(temp);
}


//deleting any node other than the first one
void delete_node(node *temp, head *q)
{
    q -> N -= 1;
    temp = temp -> next;

    if((temp -> next) != NULL){
        temp -> next -> prev = temp -> prev;
        temp -> prev -> next = temp -> next;

    }else{
        q -> last -> prev -> next = NULL;
        q -> last = q -> last -> prev;
    }

    free_node(temp);
}


//copying a node
node *copy_node(node *p, node *temp)
{
    temp -> id = p -> id;

    strcpy(temp -> baza -> name, p -> baza -> name);

    strcpy(temp -> baza -> country, p -> baza -> country);

    temp -> baza -> probability =  p -> baza -> probability;

    temp -> baza -> statistics[0] =  p -> baza -> statistics[0];

    temp -> baza -> statistics[1] =  p -> baza -> statistics[1];

    return temp;
}


//transfer of the node
void transfer_node(node *p, node *temp, head *q)
{
    /*I create a new node, and copy the information
     of the one that needs to be moved to it,
    and assign the necessary values to the pointers,
    and just delete that node, but it is deleted
     where this function is called */
    int f = 0;
    node *p1 = malloc(sizeof(node));//create
    node *p3;

    if(p == q -> first)
    {
        f = 1;
        p3 = add_first(q);
    }

    q -> N += 1;
    malloc_node(p1);
    p1 = copy_node(temp, p1);//copy

    p1 -> next = p;
    p1 -> prev = p -> prev;
    p1 -> prev -> next = p1;

    p -> prev = p1;

    if(f == 1){
        delete_first(q);
        free(p3);
    }
}


//copy of the list
void copy_list(head *q1, head *q)
{
    node *temp1 = create_node(q1);;
    node *temp = q -> first;

    while(temp -> next != NULL)
    {
        temp1 = copy_node(temp, temp1);

        temp = temp -> next;
        add_last(q1);
        temp1 = temp1 -> next;
    }

    temp1 = copy_node(temp, temp1);
}
