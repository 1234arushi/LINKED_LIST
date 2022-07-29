//https://www.geeksforgeeks.org/find-pairs-given-sum-doubly-linked-list/
#include <bits/stdc++.h>
using namespace std;
//DLL
struct node
{
    int data;
    struct node *next,*prev;
};
void pairsum(struct node *head,int x)

{
    struct node *left=head;
    struct node *right=head;
    while(right->next!=NULL)
    {
        right=right->next;
    }
    
    bool found=false;
    
    //second->next!=first dry run
    while(left!=right && right->next!=left)
    {
        if((left->data+right->data)==x)
        {
            found=true;
            cout<<"("<<left->data<<","<<right->data<<")"<<endl;
            
            left=left->next;
            right=right->prev;
            
        }
        else
        {
            if((left->data+right->data)<x)
            {
                left=left->next;
            }
            else
            {
                right=right->prev;
            }
        }
        
    }
    if(found==false)
    {
        cout<<"No pair found";
    }
}
void insert(struct node **head,int data)
{
    //inserting node at begining of DLL
    struct node *temp=new node;
    temp->data=data;
    temp->next=temp->prev=NULL;
    if(!(*head))//head->empty
    {
        (*head)=temp;
    }
    else
    {
        temp->next=(*head);
        (*head)->prev=temp;
        (*head)=temp;
    }
}
int main() {
	struct node *head=NULL;
	insert(&head,9);
	insert(&head, 8);
    insert(&head, 6);
    insert(&head, 5);
    insert(&head, 4);
    insert(&head, 2);
    insert(&head, 1);
    int x = 7;
    
    pairsum(head,x);
	return 0;
}
