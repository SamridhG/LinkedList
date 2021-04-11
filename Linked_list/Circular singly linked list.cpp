/*
// circular singly linked list
// insertion
// deletion
// reverse 
*/
 
#include<iostream>
using namespace std;
class node{    //decleration of node
	public:
	int data;       //storing data
	node *next;  // pointer
	node(int data)   // constructor
	{
		this->data=data;
		this->next=NULL;
	}
};
node* create_node(node *head) // creating node one by one
{
	int a;
	cin>>a;
	node *temp;
	temp=head;
	// checking wheather the list is empty or note
	if(temp==NULL)// if empty
	{
		head=new node(a);
		head->next=head;// pointing head next to head for making circular
	}
	else // if not empty
	{
		while(temp->next!=head)// finding the last node (last node always point firstnode as it circular
		{
			temp=temp->next;
		}
		temp->next=new node(a);// adding node to last node
		temp->next->next=head;// pointing the added last node to first
	}
	return head; 
}
void display(node *head)
{
	node *temp;	  
	temp=head;
	/*while(temp->next!=head)// while the temp didnt point the head make loop for printing element
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<temp->data;// last node point head and not node data didnt print in loop
                     // for that last node cout<<data print
                     //or
      */  do{
        	cout<<temp->data<<" ";
        	temp=temp->next;
		}while(temp!=head);            
}
int size(node *head)// function for size of circular singly linked list
{
	int count=1;
	node *temp;
	temp=head;
	while(temp->next!=head)//while temp didnt point head count the number of node
	{
		temp=temp->next;
		count++;
	}
	return count;
}
node * insertion(node *head,int position,int data)// function for inserting data at any position 
{
	if(position==1)// to insert at first
	{
	node *temp,*temp2;
	temp=head;
	temp2=head;
	head=new node(data);// head pointing new node 
	head->next=temp;// head node pointing rest of node
	while(temp->next!=temp2)// finding the last node
	{
		temp=temp->next;
	}
	temp->next=head;// point the updated head node by last node of list
}
else if(position<=size(head))// when node have to insert at b/w the any node 
{
	node *temp,*temp2;
	temp=head;
	int i=1;
	while(i<position)// finding that position in which we have to insert
	{
		temp2=temp;// previous node of positioned node 
		temp=temp->next;
		i++;
	}
	temp2->next=new node(data);// in previous next point new node
	temp2->next->next=temp;// in new node point the positioned node we finded
}
else// when we have to insert at last of node
{
	node *temp=head;
	while(temp->next!=head)// finding the last node which point the head
	{
		temp=temp->next;
	}
	temp->next=new node(data);// in last node point new node 
	temp->next->next=head;//unow point the head by updated new node which at last 
}
	return head;
}
node* deletion(node *head,int position)// function for deleting any node in list
{
	if(position==1)// deleteing first node of list
	{
	node *temp,*temp2;
	temp=head;// storing head in another pointer
	head=head->next;// updating head to head next
	temp2=head;
	while(temp2->next!=temp)// finding the last node which pointing old head
	{
		temp2=temp2->next;
	}
	temp2->next=head;// pointing the last node to the updated new head
	delete temp;// deleting the first node
    }
    else if(position==size(head))// deleting the last node
    {
    	node *temp,*temp2;
    	temp=head;
    	while(temp->next!=head)// finding the last node
    	{
    		temp2=temp;// storing one previous node in another node
    		temp=temp->next;
		}
		temp2->next=head;// pointing the last node previous to the head
		delete temp;// deleting the last node
	}
    else// deleting any node in b/w the list
    {
    	node *temp,*temp2;
    	temp=head;
    	int i=1;
    	while(i<position)// finding the position which we have to delete
    	{
    		temp2=temp;// storing one node previous to another node
    		temp=temp->next;
    		i++;
		}
		temp2->next=temp->next;// pointing one node previous to the next node of deletion node 
		delete temp;// delete the finded position node
	}
	
	return head;
}
void reverse(node *head)// for reversing the circular linked list
{
	node *temp,*temp2,*temp3;
	temp=head;
	while(temp->next!=head)// finding the last node 
	{
		temp=temp->next;
	}
	temp2=temp;// last node to another node
	temp=head;// head to another node
	while(head->next!=temp)// incersing head till head node didn't point head node 
	{
		temp3=head;// storing the node to other
		head=head->next;// incerese head
		temp3->next=temp2;//changing the pointer to the previous one
		temp2=temp3;// change previous pointer to next just like u do in singly list
	}
	head->next=temp2;// the last node pointing previous one 
	display(head);
}
int main()
{
	int n;
	node *head=NULL;
	cout<<"Enter:-";
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		head=create_node(head);
	}
	display(head);
	int p,d;
       cout<<"\n\nEnter the position :-";
       cin>>p;
       cout<<"Enter the data:-";
       cin>>d;
       head=insertion(head,p,d);
      cout<<endl<<size(head);
       cout<<endl;
     display(head);
        cout<<"\n\nEnter the position to delete:-";
       cin>>p;
       head=deletion(head,p);
      display(head);
      cout<<endl;
      cout<<"\n After reversing:-\n";
      reverse (head);
	return 0;
	
}
