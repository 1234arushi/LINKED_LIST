//https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1
 
//method:hashing(addresses of linked list nodes)
//TC->O(N)  SC->O(N)

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    struct Node* next;
};

Node* newNode(int key)
{
    Node* temp = new Node;
    temp->key = key;
    temp->next = NULL;
    return temp;
}

// A utility function to print a linked list
void printList(Node* head)
{
    while (head != NULL) {
        cout << head->key << " ";
        head = head->next;
    }
    cout << endl;
}
void hashAndRemove(Node* head)
{
    unordered_set<Node*> m;
    Node*prev;
    while(head!=NULL)
    {
        if(m.find(head)==m.end())
        {
            m.insert(head);
            prev=head;
            head=head->next;


        }
        else
        {
            prev->next=NULL;
            break;

        }

    }


}
int main()
{
    Node* head = newNode(50);
    head->next = head;
    head->next = newNode(20);
    head->next->next = newNode(15);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(10);

    /* Create a loop for testing */
    head->next->next->next->next->next = head->next->next;

    // printList(head);
    hashAndRemove(head);

    printf("Linked List after removing loop \n");
    printList(head);

    return 0;
}



//{ Driver Code Starts
// driver code

#include <iostream>
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

bool isLoop(Node* head)
{
    if(!head) return false;
    
    Node* fast = head->next;
    Node* slow = head;
    
    while( fast != slow)
    {
        if( !fast || !fast->next ) return false;
        fast=fast->next->next;
        slow=slow->next;
    }
    
    return true;
}

int length(Node* head)
{
    int ret = 0;
    while(head)
    {
        ret++;
        head = head->next;
    }
    return ret;
}


// } Driver Code Ends
/*
structure of linked list node:

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

*/

class Solution
{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
       
        
       
        
        //another method:
        
        /*if(head==NULL || head->next==NULL)
        {
            return ;
        }
        Node *slow=head;
        Node *fast=head;
        slow=slow->next;
        fast=fast->next->next;
        while(fast!=NULL && fast->next!=NULL)
        //while(fast && fast->next)
        {
            if(slow==fast)
            {
                break;
            }
            slow=slow->next;
            fast=fast->next->next;
        }
        
        //if loop exists i.e while loop ended bcz of slow==fast
        if(slow==fast)
        {
            slow=head;
            
            //circular LL
            if(slow==fast)//slow=fast=head
            {
                while(fast->next!=slow)
                {
                    fast=fast->next;
                }
            }
            else//slow=fast 
            {
                while(slow->next!=fast->next)
                {
                    slow=slow->next;
                    fast=fast->next;
                }
                
            }
            fast->next=NULL;
        }*/
        
        
        
        
        
        
        //My method :not working   :(
        
        
        /*
        5
        7 58 36 34 16
        1*/
        
       /*Node *slow=head;
        Node *fast=head;
        
        Node *meet;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            {
                meet=slow;
                break;
                
            }
        }
        //it must be that while loop ends not necessary its bcz of if 
        //statement in while loop
        if(slow==fast)
        {
            Node *start=head;
            Node *prev;
            while(start!=meet)
            {
                start=start->next;
                prev=meet;
                meet=meet->next;
            }
            prev->next=NULL;
        }*/
        
        // code here
        // just remove the loop without losing any nodes
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
        ob.removeLoop(head);
        
        if( isLoop(head) || length(head)!=n )
            cout<<"0\n";
        else
            cout<<"1\n";
    }
	return 0;
}

// } Driver Code Ends
