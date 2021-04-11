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
class list{
	public:
	node *head;
	node *tail;
	list()
	{
		head=NULL;
		tail=NULL;
	}
	void Push(int data)
	{
		if(head==NULL)
		{
			head=new node(data);
			tail=head;
		}
		else
		{
			node *temp=head;
			while(temp->next!=NULL)
			{
			  temp=temp->next;
			}
			temp->next=new node(data);
			tail=temp->next;
		}
	}
	int size()
	{
		int count;
		node *temp=head;
		while(temp!=NULL)
		{
			count++;
			temp=temp->next;
		}
		return count;
	}
	void insert(int pos,int data)
	{
		if(pos==1)
		{
			node *temp=head;
			head=new node(data);
			head->next=temp;
		}
		else if(pos==size())
		{
			tail->next=new node(data);
			tail=tail->next;
		}
		else
		{
			int c=1;
			node *prevs=NULL,*temp=head;
			while(c<pos)
			{
				prevs=temp;
				temp=temp->next;
				c++;
			}
			
			prevs->next=new node(data);
			prevs->next->next=temp;
		}
	}
	void del(int position)
	{
		if(position==1)
		{
			node *temp;
			temp=head;
			head=head->next;
			delete(temp);
		}
		else if(position==size())
		{
			node *temp=head;
			while(temp->next!=tail)
			{
				temp=temp->next;
			}
			node *temp2;
			temp2=temp->next;
			temp->next=NULL;
			delete(temp2);
		}
		else if(position>size())
		{
			cout<<"\n*Position doesnt exist*\n";
		}
		else
		{
			int c=1;
			node *prevs=NULL,*temp=head;
			while(c<position)
			{
				prevs=temp;
				temp=temp->next;
				c++;
			}
			
			prevs->next=temp->next;
			delete(temp);
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
	
};
int main()
{
	cout<<"Press 1 for Enter data>>\nPress 2 for delete Node>>\nPress 3 for Enter node at any position>>\nPress 4 for Display>>";
    int n;
    list H;
    m:
    cout<<"\n Choose->";
    cin>>n;
    if(n==1)
    {
    	int s;
    	cin>>s;
    	H.Push(s);
	}
	else if(n==2)
	{
		int p;
		cout<<"\nEnter position>>";
		cin>>p;
		H.del(p);
	}
	else if(n==3)
	{
		int x,y;
		cout<<"\nEnter position";
		cin>>x;
		cout<<"\nEnter the data";
		cin>>y;
		H.insert(x,y);
		
	}
	else if(n==4)
	{
		H.display();
	}
	goto m;
}
