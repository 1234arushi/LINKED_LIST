//https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1
//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node* reverse(Node* head)
    {
        Node *next=NULL;
        Node *prev=NULL;
        Node *curr=head;
        while(curr!=NULL)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
        
    }
    
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        
        first=reverse(first);
        second=reverse(second);
        
        int carry=0;
        Node *head=NULL;
        
        while(first!=NULL || second!=NULL || carry==1)
        {
            int val=carry;//take previous carry also
            if(first!=NULL)//what if first==NULL but second is not so we 
            //don't want first last node val to be added
            {
                val+=first->data;
                first=first->next;
            }
            if(second!=NULL)
            {
                val+=second->data;
                second=second->next;
            }
            
            carry=val/10;//new carry
           
            
            //inserting elements at the begining so that we
            //do not have to reverse in the end
            Node *newnode=new Node(val%10);
            
            newnode->next=head;
            head=newnode;
            
            
        }
        return head;
        
        // code here
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends
