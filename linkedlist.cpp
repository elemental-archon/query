// operations on linked list
#include<stdio.h>
#include<stdlib.h>


struct Node{
  int data;
  struct Node *next;
};

// traversing the list
void list_traverse(struct Node *ptr)
{
    while(ptr!=NULL)
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// functions for insertion operations

struct Node *insertAtBegining(struct Node *head, int data)
{
    struct Node *ptr = (struct Node*)calloc(1,sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;

    return ptr;
}

struct Node *insertAtIndex(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node*)calloc(1,sizeof(struct Node));
    struct Node *p = head;
    int i = 0;
    while(i!=index-1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return ptr;
}

struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *ptr = (struct Node*)calloc(1,sizeof(struct Node));
     ptr->data = data;
    struct Node *p =head;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return ptr;
}

struct Node *insertAfterNode(struct Node *previous, int data)
{
    struct Node *ptr = (struct Node*)calloc(1,sizeof(struct Node));
    ptr->data = data;
    ptr->next = previous->next;
    previous->next = ptr;
    return ptr;
}

// functions for deletion operations
struct Node *deleteAtStart(struct Node *head)
{
    struct Node *ptr = head;
    head = ptr->next;
    free(ptr);  //deallocating the memory
    return head;
}
struct Node *deleteAtindex(struct Node *head, int index)
{
    struct Node *p = head;
    int i = 0;
    while(i!=index-1)
    {
        p = p->next;
        i++;
    }
    struct Node *q;
    q = p->next;
    p->next = q->next;
    free(q);  //deallocating the memory
    return p;
}
struct Node *deleteAtEnd(struct Node *head)
{
    struct Node *p = head;
    struct Node *q = head->next;
    while(q->next!=NULL)
    {
        q=q->next;
        p=p->next;
    }
    
    p->next = q->next;
    free(q);   //deallocating the memory
    return head;
}
struct Node *deleteAftreNode(struct Node *previous)
{
    struct Node *q = previous->next;
    previous->next = q->next;
    free(q);   //deallocating the memory
    return previous;
}

// main

int main(void)
{
    struct Node *head = NULL;
    struct Node *second = NULL;
    struct Node *tail = NULL;

    head = (struct Node*)calloc(1,sizeof(struct Node));
    second = (struct Node*)calloc(1,sizeof(struct Node));
    tail = (struct Node*)calloc(1,sizeof(struct Node));

    head->data = 65;
    head->next = second;

    second->data = 78;
    second->next = tail;

    tail->data = 89;
    tail->next = NULL;
    
    list_traverse(head);
    printf("\n\n");
    //operations for insertion
    head = insertAtBegining(head, 90);
    insertAtIndex(head,45,3);
    insertAtEnd(head,23);
    insertAfterNode(second,97);
    list_traverse(head);

    printf("\n\n");
    //operations for deletion
    head = deleteAtStart(head);
    deleteAtindex(head,3);
    deleteAtEnd(head);
    deleteAftreNode(second);
    list_traverse(head);

    return 0;
}
