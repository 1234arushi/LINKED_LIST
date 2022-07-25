//https://practice.geeksforgeeks.org/problems/detect-loop-in-linked-list/1

//Method 2:his solution requires modifications to the basic 
//linked list data structure
//->done in codeblocks
#include<bits/stdc++.h>
using namespace std;
struct node
{

    int data;
    int flag;
    struct node*next;//it's also a box of LL kind
    //pointing to LL box

};

void push(struct node**head,int data)
{
    //inserting elements at front

    struct node*newnode=new node;
    newnode->data=data;
    newnode->flag=0;
    newnode->next=(*head);
    (*head)=newnode;
}
void printlist(struct node**head)
{
    //verifying whether elements inserted from begining:verified YES!!
    struct node*temp=(*head);
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }


}
bool detectloop(struct node*h)
{
    while(h!=NULL)
    {

        if(h->flag==1)//if visited again
        {

            return true;
        }
        h->flag=1;//first time visited
        h-h->next;
    }
    return false;


}
int main()
{

    struct node *head=NULL;
    push(&head,20);
    push(&head,4);
    push(&head,15);
    push(&head,10);
    printlist(&head);
    //creating a loop for testing
    head->next->next->next->next=head;
    if(detectloop(head))
    {

        cout<<"Loop found";
    }
    else
    {

        cout<<"No loop";
    }
    return 0;

}

//{ Driver Code Starts
//Initial template code for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;
    
    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}


// } Driver Code Ends
//User function template for C++

/*

struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
    
    

*/
class Solution
{
    public:
    //Function to check if the linked list has a loop.
    bool detectLoop(Node* head)
    {
        //Method 3:Floyd cycle detection
        //TC->O(N) SC->O(1)
        Node *fast=head;//takes 2-step at a time
        Node *slow=head;//takes 1-step at a time
        while(fast!=NULL && fast->next!=NULL)
        //fast==NULL :: odd no. of elements
        //fast->next==NULL :: even no. of elements
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            {
                return true;
            }
        }
        return false;
        
        
        
        
        //Method 1:Hashing approach
        //TC->O(n)::Only one traversal of the loop is needed.
        //SC->O(n)::n is the space required to store the value in hashmap.
        /*unordered_set<Node*> s;
        while(head!=NULL)
        {
            if(s.find(head)!=s.end())//if we find that head in set already
            {
                return true;//loop exists
            }
            s.insert(head);//if not then insert head in set
            head=head->next;
        }
        return false;*/
        
        // your code here
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, num;
        cin>>n;
        
        Node *head, *tail;
        cin>> num;
        head = tail = new Node(num);
        
        for(int i=0 ; i<n-1 ; i++)
        {
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
        }
        
        int pos;
        cin>> pos;
        loopHere(head,tail,pos);
        
        Solution ob;
        if(ob.detectLoop(head) )
            cout<< "True\n";
        else
            cout<< "False\n";
    }
	return 0;
}

// } Driver Code Ends
