//https://practice.geeksforgeeks.org/problems/remove-duplicates-from-an-unsorted-linked-list/1
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

void print(Node *root)
{
Node *temp = root;
while(temp!=NULL)
{
cout<<temp->data<<" ";
temp=temp->next;
}
}


// } Driver Code Ends
/*
The structure of linked list is the following

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
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
        //using maps:TC->O(N)  SC->O(N)
        if(head==NULL||head->next==NULL)
        {
            return head;
        }
        unordered_set<int> s;
        Node *temp=head;
        Node *prev;
        while(temp!=NULL)
        {
            if(s.find(temp->data)==s.end())//not found in set
            {
                s.insert(temp->data);
                prev=temp;
                
            }
            else
            {
                prev->next=temp->next;
                free(temp);//how will this work?
                //will it free that duplicate only
                
            }
            temp=temp->next;
        }
        return head;
     // your code goes here
    }
};


//{ Driver Code Starts.

int main() {
	// your code goes here
	int T;
	cin>>T;
	
	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;
 
		for(int i=0;i<K;i++){
		int data;
		cin>>data;
			if(head==NULL)
			head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp=temp->next;
			}
		}
		
	    Solution ob;
		Node *result  = ob.removeDuplicates(head);
		print(result);
		cout<<endl;
		
	}
	return 0;
}
// } Driver Code Ends
