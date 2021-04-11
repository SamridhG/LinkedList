#include<iostream>
using namespace std;
class node{
public:
	int a;
     node *p;
};
node *head=NULL;
node* createnode()
{
	node *temp;
	temp=(node *)new (node);
	return temp;
}
void nodevalue()
{
	node *c;
	c=createnode();
	cin>>c->a;
	c->p=NULL;
	if(head==NULL)
	{
		head=c;
	}
	else
	{
		node *j;
		j=head;
		while(j->p!=NULL)
		{
			j=j->p;
		}
		j->p=c;
	}
}
void print()
{
	node *i;
	i=head;
	while(i!=NULL)
	{
		cout<<i->a<<endl;
		i=i->p;
	}
}
void insertdata(int j)
{
	node *poll;
	poll=createnode();
	poll->a=j;
	poll->p=NULL;
	node *tem;
	tem=head;
	while(tem->p!=NULL)
	{
		tem=tem->p;
	}
	tem->p=poll;
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		nodevalue();
	}
	print();
	int j;
	cin>>j;
	insertdata(j);
	cout<<endl<<endl;
	print();
}
