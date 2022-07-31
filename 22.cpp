//https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1
//{ Driver Code Starts
#include <bits/stdc++.h>

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

using namespace std;

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node* flatten (Node* root);

int main(void) {

	int t;
	cin>>t;
	while(t--){
    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
	struct Node * head=NULL;
	struct Node * pre=NULL;
	struct Node * tempB=NULL;
	struct Node * preB=NULL;
		cin>>n;
        int work[n];
		for(int i=0;i<n;i++)
            cin>>work[i];
		for(int i=0;i<n;i++){
			m=work[i];
			--m;
			int data;
			scanf("%d",&data);
			temp = new Node(data);
			temp->next = NULL;
			temp->bottom = NULL;
			
			if(flag){
				head = temp;
				pre = temp;
				flag = 0;
				flag1 = 1;
			}
			else{
				pre->next = temp;
				pre = temp;
				flag1 = 1;
			}
			for(int j=0;j<m;j++){
				
				int temp_data;
				scanf("%d",&temp_data);
				tempB = new Node(temp_data);

				if(flag1){
					temp->bottom=tempB;
					preB=tempB;
					flag1=0;
				}
				else{
					preB->bottom=tempB;
					preB=tempB;
				}
			}
		}
		   Node *fun = head;
		   Node *fun2=head;

            Node* root = flatten(head);
            printList(root);
            cout<<endl;

	}
	return 0;
}

// } Driver Code Ends


/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */
Node *mergetwolists(Node *a,Node *b)
{
    Node *temp=new Node(0);
    //temp will have next and bottom ptr
    Node *res=temp;
    while(a!=NULL &&  b!=NULL)
    {
        if(a->data < b->data)
        {
            temp->bottom=a;
            temp=a;//=temp->bottom
            a=a->bottom;
        }
        else
        {
            temp->bottom=b;
            temp=b;//=temp->bottom
            b=b->bottom;
            
        }
    }
    
    //if some elements then temp->bottom points to all the 
    //element left
    /*if(a)
    {
        temp->bottom=a;
        
    }
    else
    {
        temp->botoom=b;
    }*/
    
    while(a!=NULL)
    {
        temp->bottom=a;
        temp=a;//=temp->bottom
        a=a->bottom;
    }
    while(b!=NULL)
    {
        temp->bottom=b;
        temp=b;//=temp->bottom
        b=b->bottom;
    }
    return res->bottom;//head
    
}
Node *flatten(Node *root)
{
    if(root==NULL || root->next==NULL)
    {
        return root;
    }
    
    //recur for list on right
    root->next=flatten(root->next);
    //root->next = flatten() is taken so that it links the 
    //sorted LL on right with its root on left
    
    root=mergetwolists(root,root->next);
    //root= mergetwolists() isliye cuz ab new combined sorted
    //list id "root"
    
    return root;
   // Your code here
}

