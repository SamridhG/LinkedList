#include<iostream>
using namespace std;
class Linkedlist{
	public:
		int data;
		Linkedlist *next;
		Linkedlist(int data)
		{
			this->data=data;
			this->next=NULL;
		}
};
Linkedlist* push(Linkedlist* head,int data)
{
	Linkedlist *temp=head;
	if(temp==NULL)
	{
		head=new Linkedlist(data);
	}
	else
	{
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=new Linkedlist(data);
	}
	return head;
}
Linkedlist* REVERSE(Linkedlist* head)
{
	Linkedlist *temp,*temp2=NULL;
	while(head!=NULL)
	{
		temp=head;
		head=head->next;
		temp->next=temp2;
		temp2=temp;
	}
	return temp2;
}
void print(Linkedlist* head)
{
	Linkedlist *temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;	
	}
}
int main()
{ 
int n,data;
Linkedlist *top=NULL;
	cout<<"Enter size>>";
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>data;
		top=push(top,data);
	}
	cout<<endl;
	print(top);
	top=REVERSE(top);
	cout<<endl;
	print(top);
}
