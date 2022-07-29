//https://practice.geeksforgeeks.org/problems/sort-a-linked-list/1
//{ Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
    Node* findmid(Node* head)
    {
        Node* slow=head;
        Node* fast=head->next;//fast=head:::runtime error??
        while(fast != NULL && fast->next != NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    Node* merge(Node* left,Node* right)
    {
        if(left == NULL)
        {
            return right;
        }
        if(right == NULL)
        {
            return left;
        }
        
        
        Node* ans= new Node(-1);//new node
        
        //ans is equal to temp so in the end we have 
        //the top Node
        Node* temp=ans;//reference ptr for new node=ans
        
        //while either left or right becomes NULL
        while(left != NULL && right != NULL)
        {
            if(left->data < right->data)
            {
                //-1 -> left->data ->...
                temp->next=left;
                temp=left;// temp=temp->next;
                left=left->next;
                
            }
            else
            {
                temp->next=right;
                temp=right;// temp=temp->next;
                right=right->next;
            }
           
            
        }
        
        //any remaining Node in left or right gets
        //inserted in the temp List
        while(left != NULL)
        {
            temp->next=left;
            temp=left;//temp=temp->next;
            left=left->next;
            
            
        }
        while(right != NULL)
        {
            temp->next=right;
            temp=right;//temp=temp->next;
            right=right->next;
            
            
        } 
        // return the head of the sorted list
        ans=ans->next;//removing the dummy node
        return ans;
        
        
    }
    
   
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node *head) {
        //base case:if list is empty or there is a 
        //single element then it's already soretd
        
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        
        //breaking linked list into two halves
        Node* mid=findmid(head);
        
        Node* left=head;
        Node* right=mid->next;
        mid->next=NULL;
        
        //recursive calls to sort both the halves
        left=mergeSort(left);
        right=mergeSort(right);
        
        //merge
        Node* result=merge(left,right);
        
        return result;
        // your code here
    }
};


//{ Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}
// } Driver Code Ends
