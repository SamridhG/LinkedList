#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node *next;
		node(int data)
		{
			this->data=data;
			this->next=NULL;
		}
};
node *head=NULL;
void insert(int data)
{
	if(head==NULL)
	{
		head=new node(data);
	}
	else
	{
		node *temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=new node(data);
	}
}
void bubble(int n)
{
	
	int i,j;
	for(i=0;i<n-1;i++)
	{
		node *temp=head;
		for(j=0;j<n-1-i;j++)
		{
			if(temp->data>temp->next->data)
			{
				swap(temp->data,temp->next->data);
			}
			temp=temp->next;
		}
	}
}
void display()
{
	node *temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int a;
		cin>>a;
		insert(a);
	}
	bubble(n);
	display();
}
