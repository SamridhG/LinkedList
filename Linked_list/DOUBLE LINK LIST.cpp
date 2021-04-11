#include<iostream>
using namespace std;
class node{//creating class for double link list
	public:
	int data;      // storing data
	node* next;   //for pointing next node
	node* prev;// for pointing previous node
	node(int data)// constructor
	{
		//use of this pointer
		this->data=data;
		this->next=NULL;
		this->prev=NULL;
	}
};
node* create(node *head)// function for creating node
{
	int a;
	cin>>a;// data enter to store
	node* temp;// creating temperary node
	temp=head;
	if(temp==NULL)// if head is null
	{
		head=new node(a);
	}
	else{// if not
		while(temp->next!=NULL)// find the last node for insert
		{
			temp=temp->next;
		}
		temp->next=new node(a);// linking new node with last node
		temp->next->prev=temp;// pointing previous node to new node previous section
	}
	return head;
}
void dislay(node *head)// function for printing
{
	node *temp,*temp1;
	temp=head;
	temp1=head;
	cout<<endl<<endl;
	while(temp!=NULL)// checking wheather a current nodenot a null node
	{
		cout<<temp->data<<" ";// if not null print data of current node
		temp=temp->next;// point next node
	}
	cout<<endl<<endl;
	
		while(temp1->next!=NULL)//going to the last node for printing list in reverse by using
		{                        // previous pointing node
			temp1=temp1->next;
		}
	while(temp1!=NULL)// after finding last node checking
	{
		cout<<temp1->data<<" ";// printing 
		temp1=temp1->prev;// pointing backword for pprevious node data
	}
}
int size(node *head) // countig for size
{
	node *temp;
	temp=head;
	int count=0;
	while(temp!=NULL)// checking current node not null
	{
		count++;// increasing count if curren node not null 
		temp=temp->next;// pointing to next node
	}
	return count;
}
node* insertion(node *head,int position,int data)//function for inserting new data in list
{
	int n;
	n=size(head);
	if(position==1)// if inserting at position first
	{
	node *temp;
	temp=head;// point head to another pointer
	head=new node(data);// now head point new node
	head->next=temp;//head next point to the remaing list 
	temp->prev=head;// and previous of next pointer point to head 
	return head;
	}
	else if(position>n)// if position is greater the the list mean to add new node at last
	{
		node *temp;
		temp=head;
		while(temp->next!=NULL)// find the last node of list
		{
			temp=temp->next;
		}
        temp->next=new node(data);// after find point last node next to the nw node 
        temp->next->prev=temp;// and new node previous to the last node
        return head;
	}
	else// if we have to insert at intermediate of list
	{
		node *temp;
		temp=head;
		int i=1;
		while(i<position)// find node at which position node should be insert
		{
			temp=temp->next;
			i++;
		}
		node *temp1;
		temp1=temp->prev;// point previous of that node to another pointer
		temp->prev=new node(data);// now  in previous of that node point new pointer
		temp->prev->next=temp;// and the next of new pointer point that node which our position our node inserting
		temp->prev->prev=temp1;// now point the previous of new node to the previous of that poistion node in which we inserting
		temp1->next=temp->prev;// in next of position-1 node point the new node
		return head;		
	}
    
 } 
 node *deletion(node *head,int node_no)// function for deleting node
 {
 	int siz;
 	siz=size(head);
 	if(node_no>siz)// if entered node to delete is node existing
 	{
 		cout<<"Node number excedd";
 		return head;
	 }
	 else// if existing
	 {
	 	if(node_no==1)// if we have to delete first node
	 	{
	 		node *temp;
	 		temp=head;// point the pointer to new pointer
	 		head=head->next;// change the head to next pointer
	 		head->prev=NULL;// make the previous section of next pointer null
	 		delete temp;//delete the new pointer in which old head addresss was there
	 		return head;
		 }
		 else if(node_no<siz)//if the deletion node between the list
		 {
		 	int i;
		 	i=1;
		 	node *temp;
		 	temp=head;
		 	while(i!=node_no)//find the deleting node
		 	{
		 		temp=temp->next;
		 		i++;
			 }
			// after finding the deleting node
			 temp->next->prev=temp->prev;// in the previous of next node of deletion node point the previous of deletion node
			 temp->prev->next=temp->next;// deleted node ke piche wale node k next m deletd node k next ka adress
			 delete temp;
		 }
		 else// deleting the last node of linked list
		 {
		 	node *temp;
		 	temp=head;
		 	while(temp->next!=NULL)// fi d the last node
		 	{
		 		temp=temp->next;
			 }
			 temp->prev->next=NULL;// in the previous node of last node , next should be null
			 delete temp; // and delete last node
			 return head;
		 }
	 }
	 return head;
 }
int main()
{
	int n;
	node *head=NULL;
	cout<<"Enter:-";
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		head=create(head);
	}
	int p,d;
	dislay(head);
	cout<<"\nenter position and data:-";
	cin>>p>>d;
	head=insertion(head,p,d);
		cout<<endl<<endl;
		dislay(head);
		cout<<endl<<endl;
		cout<<"Enter node number to delete:";
		int node;
		cin>>node;
		head=deletion(head,node);
		dislay(head);
}
