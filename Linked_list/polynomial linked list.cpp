#include<iostream>
#include<string>
using namespace std;
class node{
	public:
		string s;
		node *next;
		node(string S)
		{
			this->s=S;
			this->next=NULL;
		}
};
node *head=NULL;
void push(string s)
{
	if(head==NULL)
	{
		head=new node(s);
	}
	else
	{
		node *temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=new node(s);
	}
}
void display()
{
node *temp=head;
		while(temp!=NULL)
		{
			cout<<temp->s<<" ";
			temp=temp->next;
		}	
}
int main()
{
	string s;
	for(int i=0;i<5;i++)
	{
		cin>>s;
		push(s);
	}
	display();
}
