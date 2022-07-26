//https://www.geeksforgeeks.org/move-last-element-to-front-of-a-given-linked-list/
#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
void push(Node **head,int key)
{
    //inserting elements at the begining
    Node *newnode=new Node();
    newnode->data=key;
    newnode->next=(*head);
    (*head)=newnode;



}
void printlist(Node *head)
{


    Node *temp=head;
    while(temp !=NULL)
    {

        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
void movetofront(Node **head)
{

    Node *temp=*head;//Node **temp???
    Node *prev;
    while(temp->next!=NULL)//imp temp->next
    {
         prev=temp;
         temp=temp->next;


    }
    prev->next=NULL;
    temp->next=(*head);

    *head=temp;

}
int main()
{
    //class name  *ptr->obj name
    Node *head=NULL;
    push(&head,5);//& required so that changes in
    push(&head,4);//head made for printlist function
    push(&head,3);//to work
    push(&head,2);
    push(&head,1);
    cout<<"Linked list before:\n";
    printlist(head);
    movetofront(&head);//& so that changes made
                      //stored in head
    cout<<"\nLinked after removing last to front:\n";
    printlist(head);
    return 0;

}
