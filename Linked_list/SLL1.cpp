#include<iostream>
using namespace std;
class node
{
	public:
	int data;
    node *next;
    node(int data)
	{
		this->data=data;
		next=NULL;
			}		
};

node* create(node *head)
{
	node *temp,*temp2;
	temp2=head;
	int a;
	cin>>a;
	temp=new node(a);
	if(temp2==NULL)
	{
		head=temp;
	}
	else
	{
          while(temp2->next!=NULL)
          {
          	temp2=temp2->next;
		  }
		  temp2->next=temp;
	}
	return head;
}
void display(node *head)
{
	node *temp;
	temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<endl;
		temp=temp->next;
		
	}
}
int main()
{
	node *head=NULL;
	int i;
	cout<<"Enter the number of entery:-";
	cin>>i;
	for(int n=1;n<=i;n++)
	{
		head=create(head);
	}
	display(head);
}

