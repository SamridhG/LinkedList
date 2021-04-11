#include<iostream>
using namespace std;
class Node{
	public:
		int data;
		Node *next;
		Node(int data)
		{
			this->data=data;
			this->next=NULL;
		}
};
Node *head=NULL;
void INSERT(int data)
{
	if(head==NULL)
	{
		head=new Node(data);
	}
	else
	{
		Node *temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=new Node(data);
	}
}
void display()
{
 Node *temp=head;
 while(temp!=NULL)
 {
 	cout<<temp->data<<" ";
 	temp=temp->next;
 }	
}
int main()
{
	char A;
	do{
	int a;
	cout<<"Enter Element for Insertion>>> ";
	cin>>a;
	INSERT(a);
	cout<<"Press 'i' for More insertion:-- ";
	cin>>A;
	}while(A=='i');
	cout<<"Your Entered Element in node\n";
	display();	
}
