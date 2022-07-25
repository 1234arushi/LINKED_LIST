//https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
     
        //Method 2:
        //TC:O(N)  SC->O(1)???????
        
        //Method 1:
        //TC->O(N)  SC->O(n/k):For each Linked List of 
                         //size n,n/k or (n/k)+1
                        // calls will be made 
                        //during the recursion.
        if(head==NULL)
        {
            return NULL;
        }
        struct node *curr=head;
        struct node *next=NULL;
        struct node *prev=NULL;
        int count_k=0;
        while(curr!=NULL && count_k<k)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            count_k++;
        }
        if(next!=NULL)
        {
            head->next=reverse(next,k);
            
        }
        return prev;
        // Complete this method
    }
};


//{ Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
     
    return(0);
}


// } Driver Code Ends
