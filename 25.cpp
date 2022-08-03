//https://practice.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1
//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        //Method 2:TC:O(N)  SC:O(1)
        if(!head || !(head->next))
        {
            return head;
        }
        //creating 3 dummy nodes to point to beginning of 
        //three linked lists.these dummy nodes are created to
        //avoid many null checks
        Node *zero=new Node(0);
        Node *one=new Node(0);
        Node *two=new Node(0);
        
        //initialize current pointers for three lists and 
        //whole lists
        Node *zeroD=zero,*oneD=one,*twoD=two;
        
        //traverse list
        Node* curr=head;
        while(curr)
        {
            if(curr->data==0)
            {
                zeroD->next=curr;
                zeroD=zeroD->next;
            }
            else if(curr->data==1)
            {
                oneD->next=curr;
                oneD=oneD->next;
            }
            else if(curr->data==02)
            {
                twoD->next=curr;
                twoD=twoD->next;
            }
            curr=curr->next;
        }
        
        //attach three lists
        
        //list:000002222
        zeroD->next=one->next?one->next:two->next;
        oneD->next=two->next;
        twoD->next=NULL;
        
        head=zero->next;//as zero=0 and zero->next=1
        
        //delete dummy nodes ??
        //will this not delete the listdddddd
        delete zero;
        delete one;
        delete two;
        return head;
        /*Method 1:
        Node* temp=head;
        int c0=0,c1=0,c2=0;
        while(temp!=NULL)
        {
            if(temp->data==0)
            {
                c0++;
            }
            if(temp->data==1)
            {
                c1++;
            }
            if(temp->data==2)
            {
                c2++;
            }
            temp=temp->next;
        }
        temp=head;
        while(temp!=NULL)
        {
            if(c0!=0)
            {
                temp->data=0;
                c0--;
            }
            else if(c1!=0)
            {
                temp->data=1;
                c1--;
            }
            else if(c2!=0)
            {
                temp->data=2;
                c2--;
            }
            temp=temp->next;
        }
        return head;*/
        
       
        // Add code here
        
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends
