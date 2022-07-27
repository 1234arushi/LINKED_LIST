//https://practice.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1
//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node* reverse(Node *head)
    {
        Node* next=NULL;
        Node* prev=NULL;
        Node* curr=head;
        while(curr!=NULL)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;//head
    }
    Node* addOne(Node *head) 
    {
        head=reverse(head);
        bool f=true;
        Node *cur=head;
        while(cur!=NULL && f==true)
        {                        //h
            //first case: 9<-9<-9<-9 ::last digit
            if(cur->next==NULL && cur->data==9)
            {
                cur->data=1;
                Node *temp=new Node(0);//wtih data=0
                temp->next=head;
                head=temp;
                cur=cur->next;
            }
            //second case: 4<-5<-9
            else if(cur->data==9)
            {
                cur->data=0;
                cur=cur->next;
                //f==false not doing bcz carry has to be added
                //next digits addition has to be taken care of
            }
            else//cur->data<9
            {
                cur->data=cur->data+1;
                cur=cur->next;
                f=false;
            }
        }
        head=reverse(head);//to get orginal LL
        return head;
        // Your Code here
        // return head of list after adding one
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends
