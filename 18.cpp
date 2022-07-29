//https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1

//METHOD 2:----------------------------------------------------------------------------------------------------------------------------


//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
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




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
  //METHOD 2: TC->O(N)  SC->O(1)
    Node* getmid(Node* head)
    {
        Node* slow=head;
        Node* fast=head->next;
        while(fast!=NULL && fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    
    Node* reverse(Node* head)
    {
        Node* curr=head;
        Node* prev=NULL;
        Node* next=NULL;
        
        while(curr!=NULL)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        if(head->next==NULL)//head==NULL not checking as in 
        //constraints N begins from 1
        {
            return true;
        }
        
        //step 1:find middle
        Node* middle=getmid(head);
        
        //step 2:reverse list after middle
        Node* temp=middle->next;
        middle->next=reverse(temp);//head=middle->next??
        
        //step 3:compare both the halves
        Node* head1=head;
        Node* head2=middle->next;
        
        while(head2!=NULL)
        {
            if(head2->data!=head1->data)
            {
                return 0;
            }
            head1=head1->next;
            head2=head2->next;
        }
        
        /*step 4:repeat step 2 ->why???
        temp=middle->next;
        middle->next=reverse(temp);*/
        
        return true;
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends



//METHOD 1:----------------------------------------------------------------------------------------------------------------------------------------------

//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
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




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
//Method 1: TC->O(N)  SC->O(N)
#include<vector>
class Solution{
  private:
    bool checkpalindrome(vector<int> arr)
    {
        int n=arr.size();
        int s=0;//start
        int e=n-1;//end
        
        // N/2 time chlega ye
        while(s<=e)
        {
            if(arr[s]!=arr[e])
            {
                return 0;
            }
            s++;
            e--;
            
        }
        return 1;
    }
    
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        vector<int> arr;//for storing LL elements in it
        Node* temp=head;
        while(temp!=NULL)
        {
            arr.push_back(temp->data);
            temp=temp->next;
        }
        
        return checkpalindrome(arr);
        //Your code here
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends
