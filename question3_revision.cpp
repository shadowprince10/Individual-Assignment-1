#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
    int number;
    node *next;
}*head, *tail;


node *create_new_node(int number)
{
    node *new_node = (node*)malloc(sizeof(node));
    new_node -> number = number;
    new_node -> next = NULL; 
    return new_node;
}


/*
void pushHead(const char *s, Node** curr) {
  Node *temp = createNode(s);
    temp->next = *curr; 
    *curr = temp; 
}
*/

/*
void push_head(struct node **head, int number)
{
    node *temp = create_new_node(number); // untuk membuat node baru

    if ((*head) == NULL) // kalau linked list kosong
    {
        *head = tail = temp; // maka otomatis temp alias node baru adalah head sekaligus tail
    }

    else // kalau linked list memiliki >= 1 node
    {
        temp -> next = *head; // membuat link antara temp dengan head
        temp = *head; // setelah itu, baru bisa memindahkan head ke temp
    }
}
*/

void push_head(struct node** current, int number)
{
    node *temp = create_new_node(number);
    temp -> next = *current;
    *current = temp;
}

void search_mid(struct node *head)
{
    struct node *slow_pointer = head;
    struct node *fast_pointer = head;

    if (!head)
    {
        while (fast_pointer && fast_pointer -> next)
        {
            fast_pointer = fast_pointer -> next -> next;
            slow_pointer = slow_pointer -> next;
        }
        printf("%d\n", slow_pointer -> number);
    }
}

void print_singleLL(struct node *temp)
{
    while (temp)
    {
        printf("%d\n", temp -> number);
        temp = temp -> next;
    }
    puts("NULL");
}

int main()
{
    node* linked_list = NULL;
    int size, element;
    
    do
    {
        scanf("%d", &size);
    } while (size <= 0); 
    

    for (int i = 0; i < size; i++)
    {
        scanf("%d", &element); // ceritanya, elemen linked list-nya sudah tersorting.
        push_head(&linked_list, element);
    }

    print_singleLL(linked_list);
    search_mid(linked_list);

    return 0;
}



// Learning Resources:
// 1. https://www.mycplus.com/tutorials/data-structures/find-the-middle-element-of-linked-list-in-c/#:~:text=In%20order%20to%20find%20middle,middle%20element%20of%20linked%20list.
// 2. https://www.geeksforgeeks.org/write-a-c-function-to-print-the-middle-of-the-linked-list/