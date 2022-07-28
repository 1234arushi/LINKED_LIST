//https://practice.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1
//{ Driver Code Starts
#include<iostream>

#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int intersectPoint(struct Node* head1, struct Node* head2);

Node* inputList(int size)
{
    if(size==0) return NULL;
    
    int val;
    cin>> val;
    
    Node *head = new Node(val);
    Node *tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

/* Driver program to test above function*/
int main()
{
    int T,n1,n2,n3;

    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;
        
        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);
        
        Node* temp = head1;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        temp = head2;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}


// } Driver Code Ends


/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

//Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node* head1, Node* head2)
{
    //Another optimized sol:but less then below one
    int len1=0;
    int len2=0;
    Node *temp=head1;
    while(temp!=NULL)
    {
        len1++;
        temp=temp->next;
    }
    temp=head2;
    while(temp!=NULL)
    {
        len2++;
        temp=temp->next;
    }
    Node *curr;
    int diff;
    if(len2>len1)
    {
        diff=len2-len1;
        temp=head2;
        curr=head1;
    }
    else
    {
        diff=len1-len2;
        temp=head1;
        curr=head2;
    }
    while(diff)//bigger length diff tk traverse first
    {
        temp=temp->next;
        diff--;
    }
    //then at same node now compare
    while(curr!=temp)
    {
        curr=curr->next;
        temp=temp->next;
    }
    if(curr!=NULL)
    {
        return curr->data;
    }
    return -1;
    //most optimized sol atq striver:TLE!!!!!!!1
    /*if(head1==NULL || head2==NULL)
    {
        return -1;
    }
    Node *temp1=head1;
    Node *temp2=head2;
    while(temp1!=temp2)//not data just node must be equal
    //does node contains address
    {
        //taking temps to diff heads by just removing the diff b/w 
        //ptrs on LL and making then at same pos
        temp1=temp1==NULL?head2:temp1->next;
        temp2=temp2==NULL?head2:temp2->next;
        
    }
    if(temp1==NULL)
    {
        return -1;
    }
    int pt=temp1->data;
    return pt;//will return NULL when no intersection pt found
    //as then also temp1=temp2
    //but here -1 is to be returned when no intersection pt found*/
   
    
    // Your Code Here
}

