//https://www.geeksforgeeks.org/find-first-node-of-loop-in-a-linked-list/
#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node* next;
};

node* newnode(int data)
{
    node *temp=new node;
    temp->data=data;
    temp->next=NULL;
    return temp;
}

void printlist(node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
        
    }
    cout<<endl;
    
}

node* startptr(node* head)
{
    if(head==NULL||head->next==NULL)
    {
        return NULL;
    }
    node *slow=head,*fast=head;
    
    slow=slow->next;
    fast=fast->next->next;
    
    while(fast!=NULL && fast->next!=NULL)
    {
        if(slow==fast)
        {
            break;
        }
        slow=slow->next;
        fast=fast->next->next;
    }
    if(slow!=fast)
    {
        return NULL;
    }
    //no extra if for circular LL
    
    slow=head;
    while(slow!=fast)
    {
        slow=slow->next;
        fast=fast->next;
    }
    return slow;
}
int main()
{
    node* head = newnode(50);
    head->next = newnode(20);
    head->next->next = newnode(15);
    head->next->next->next = newnode(4);
    head->next->next->next->next = newnode(10);
 
    /* Create a loop for testing */
    head->next->next->next->next->next = head->next->next;
 
    node* res = startptr(head);
    if (res == NULL)
        cout << "Loop does not exist";
    else
        cout << "Loop starting node is " << res->data;
    return 0;
}














