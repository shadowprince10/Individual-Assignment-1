// QUESTION 1: Given two sorted linked lists L1 and L2 of size M and N respectively, merge them into one sorted linked list.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct node
{
    int number;
    struct node* next; // untuk define pointer ke node selanjutnya
}*head, *tail;

node *create_node(int number)
{
    node *new_node = (node*)malloc(sizeof(node));
    new_node -> number = number;
    new_node -> next = NULL;
    return new_node;
}

void push_head(int number)
{
    node *temp = create_node(number);

    if (!head)
    {
        head = tail = temp;
    }

    else
    {
        temp -> next = head;
        temp = head;
    }   
}

void push_tail(int number)
{
    node *temp = create_node(number); // untuk membuat node baru

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

void push_mid(int number)
{
    node* temp = create_node(number);

    if (!head)
    {
        head = tail = temp;
    }

    else if (number < head -> number)
    {
        push_head(number);
    }

    else if (number > tail -> number)
    {
        push_tail(number);
    }

    else
    {
        node *current = head;

        while (current && current -> next -> number < number)
        {
            current = current -> next;
        }

        temp -> next = current -> next;
        current -> next = temp;
    }
}

void print_singleLL()
{
    node *temp = head;

    if (!head)
    {
        return;
    }

    while (temp)
    {
        printf("%d\n", temp -> number);
        temp = temp -> next;
    }
    puts("");
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

    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &l1);
        push_mid(l1);
    }

    scanf("%d", &n);
    for (int j = 0; j < n; j++)
    {
        scanf("%d", &l2);
        push_mid(l2);
    }

    print_singleLL();

    return 0;
}


// learning Resources:
// 1. https://www.geeksforgeeks.org/merge-two-sorted-linked-lists/
// 2. https://www.techiedelight.com/merge-given-sorted-linked-lists/
// 3. https://www.tutorialspoint.com/merge-two-sorted-linked-lists-using-cplusplus
