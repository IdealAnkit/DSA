#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

void linklistTraversal(struct node* head)
{
    struct node* ptr = head;
    do{
    printf(" element is: %d \n" ,ptr->data);
    ptr = ptr->next;
    }while(ptr!=head);
}

struct node *insertAtFirst(struct node *head ,int data){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data=data;

    struct node* p = head->next;
    while(p->next != head)
    {
        p=p->next;
    }
    p->next = ptr;
    ptr->next= head;
    head =ptr;
    return head;
}

int main(){
    struct node *head;
     struct node *second;
      struct node *third;

      head=(struct node*)malloc(sizeof(struct node));
      second=(struct node*)malloc(sizeof(struct node));
      third=(struct node*)malloc(sizeof(struct node));

      //link first and second node
      head->data=8;
      head->next=second;

       //link second and third node
      second->data=12;
      second->next=third;

       //terminate the program
      third->data=18;
      third->next=head;
      printf(" Element before insertion\n");
      linklistTraversal(head);
       
     head=insertAtFirst(head ,20);
      printf("\n Element after insertion\n");
      linklistTraversal(head);
      return 0;
}