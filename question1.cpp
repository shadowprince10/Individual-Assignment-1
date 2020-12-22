// QUESTION 1: Given two sorted linked lists L1 and L2 of size M and N respectively, merge them into one sorted linked list.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>


struct node
{
    char name[255];
    int code;
    struct node* next; // untuk define pointer ke node selanjutnya
}*head, *tail;

node *create_node(const char* name, int code)
{
    node *new_node = (node*)malloc(sizeof(node));
    strcpy(new_node -> name, name);
    new_node -> code = code;
    new_node -> next = NULL;
    return new_node;
}

void push_tail(const char* name, int code)
{
    node *temp = create_node(name, code); // untuk membuat node baru

    if (!head)
    {
        head = tail = temp;
    }

    else
    {
        tail -> next = temp; // tail lama -> next adalah node baru
        tail = temp; // node baru akan menjadi tail
    }
}

/*
// Function that takes the node from the front of source and moves it to the front of the destination
void move_node(struct node* destination_ref, struct node* source_ref)
{
    if (source_ref == NULL)
    {
        return;
    }

    struct node* new_node = source_ref; // the front source node
    source_ref = source_ref -> next; // advance the source pointer
    new_node -> next = destination_ref; // link the old destination off the new node
    destination_ref = new_node;
}

struct node* merge_node(struct node* a, struct node* b)
{
    struct node merge;
    merge.next = NULL;


}
*/

int main()
{
    int m, n, l1, l2;
    struct node* result = NULL;
    struct node* x = NULL;
    struct node* y = NULL;

    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &l1);
    }

    scanf("%d", &n);
    for (int j = 0; j < n; j++)
    {
        scanf("%d", &l2);
    }

    int merge = m + n;
    for (int k = 0; k < m; k++)
    {
        for (int p = 0; p < n; p++)
        {
            if ()
            {

            }
        }
    }

    return 0;
}


// learning Resources:
// 1. https://www.geeksforgeeks.org/merge-two-sorted-linked-lists/
// 2. https://www.techiedelight.com/merge-given-sorted-linked-lists/
// 3. https://www.tutorialspoint.com/merge-two-sorted-linked-lists-using-cplusplus
