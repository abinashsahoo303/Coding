#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;    
};

struct node *head = NULL;

void insertatbegin(){
    struct node *newNode =(struct node*)malloc(sizeof(struct node));
    newNode->data =1;
    newNode->next = head;
    head = newNode;
}

void insertatend(){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data=2;
    struct node *temp1 = head;

    while(temp1->next != NULL){
        temp1 = temp1->next;
    }
    temp1->next = temp;
}

void insertafternode(struct node *ll,int data){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = ll->next;
    ll->next = temp;
}

int main(){
    insertatbegin();
    insertatend();
    insertafternode(head->next,3);
    struct node *p = head;
    while(p != NULL){
        printf("Linked list data [%d]\n",p->data);
        p=p->next;
    }
    return 0;
}
