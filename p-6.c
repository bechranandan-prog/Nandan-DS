#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void insertBeg(int x) {
    struct node *n = malloc(sizeof(struct node));
    n->data=x; n->next=head; head=n;
}

void insertEnd(int x) {
    struct node *n=malloc(sizeof(struct node)), *p;
    n->data=x; n->next=NULL;
    if(head==NULL) head=n;
    else {
        p=head;
        while(p->next) p=p->next;
        p->next=n;
    }
}

void insertAfter(int key,int x) {
    struct node *p=head;
    while(p && p->data!=key) p=p->next;
    if(p) {
        struct node *n=malloc(sizeof(struct node));
        n->data=x; n->next=p->next; p->next=n;
    }
}

void deleteFirst() {
    if(head) { struct node *p=head; head=head->next; free(p); }
}

void deleteLast() {
    struct node *p=head,*q=NULL;
    if(!head) return;
    while(p->next) { q=p; p=p->next; }
    if(q) q->next=NULL; else head=NULL;
    free(p);
}

void deleteAfter(int key) {
    struct node *p=head;
    while(p && p->data!=key) p=p->next;
    if(p && p->next) {
        struct node *q=p->next;
        p->next=q->next; free(q);
    }
}

void display() {
    struct node *p=head;
    while(p) { printf("%d -> ",p->data); p=p->next; }
    printf("NULL\n");
}

int main() {
    insertBeg(20);
    insertBeg(10);
    insertEnd(30);
    insertAfter(20,25);

    display();

    deleteFirst();
    deleteLast();
    deleteAfter(20);

    display();
    return 0;
}
