//https://practice.geeksforgeeks.org/problems/rotate-doubly-linked-list-by-p-nodes/1
//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
  int data;
  struct node*next,*prev;
  
  node(int x){
      data = x;
      next = NULL;
      prev = NULL;
  }
  
} Node;


// } Driver Code Ends
//User function Template for C++

/*
typedef struct node
{
  int data;
  struct node*next,*prev;
  
  node(int x){
      data = x;
      next = NULL;
      prev = NULL;
  }
  
} Node;
*/

class Solution {
public:
    Node *rotateDLL(Node *start,int p)
    {
        
        //METHOD 2:
        if(p==0)
        {
            return start;
        }
        Node* curr=start;
        while(p)
        {
            curr=curr->next;
            p--;
        }
        Node *tail=curr->prev;
        Node *newhead=curr;
        tail->next=NULL;
        curr->prev=NULL;
        
        while(curr->next!=NULL)
        {
            curr=curr->next;
        }
        curr->next=start;
        start->prev=curr;
        start=newhead;
        return start;
        
        /*METHOD 1:
        if(p==0)
        {
            return start;
        }
        //finding last node
        Node* temp=start;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        
        //making DLL circular
        temp->next=start;
        start->prev=temp;
        
        //move start(=head) and temp by given p
        int count=1;
        while(count<=p)
        {
            start=start->next;
            temp=temp->next;
            count++;
        }
        //now again make list un-circular
        temp->next=NULL;
        start->prev=NULL;
        return start;*/
        
        
        
        /*My method:TLE!!!!!!!!!!!
        int count=0;
        Node* last=start;
        while(last->next!=NULL)
        {
            last=last->next;
        }
        Node* head=start;
        while(head!=NULL && count<p)
        {
           
            head->prev=last->next;
            Node *newhead=head->next;
            head->next=NULL;
            last=head;
           
            
        }
        return head;*/
        //Add your code here
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,p;
        cin>>n>>p;
        struct node*start = NULL;
        struct node* cur = NULL;
        struct node* ptr = NULL;
        
        for(int i=0;i<n;i++)
        {
            int a;
            cin>>a;
            ptr=new node(a);
            ptr->data=a;
            ptr->next=NULL;
            ptr->prev=NULL;
            if(start==NULL)
            {
                start=ptr;
                cur=ptr;
            }
            else
            {
                cur->next=ptr;
                ptr->prev=cur;
                cur=ptr;
            }
        }
        Solution obj;
        struct node*str=obj.rotateDLL(start,p);
        while(1)
        {
            cout<<str->data<<" ";
            if(str->next==NULL)break;
            str=str->next;
        }
        while(str!=NULL)
        {
            cout<<str->data<<" ";
            str=str->prev;
        }
        cout<< "\n";   
    }
}


// } Driver Code Ends
