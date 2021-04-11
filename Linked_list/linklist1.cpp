#include<iostream>
using namespace std;
 typedef struct node{
	int A;
	node *link;
}node;
node *start=NULL;
node* create_node()
{
	node *n;
	n=(node*)new node;
	return n;
}
 void insert()
 {
 	node *temp,*t;
 	temp=create_node();
 	cin>>temp->A;
 	temp->link=NULL;
 	if(start==NULL)
 	{
 		start=temp;
	 }
	 else
	 {
	 	t=start;
	 	while(t->link!=NULL)
	 	{
	 		t=t->link;
		 }
		 t->link=temp;
	 }
 }
 void print()
 {
 	node* temp;
 	temp=start;
 	while(temp!=NULL)
 	{
 		cout<<temp->A<<endl;
 		temp=temp->link;
	 }
	// cout<<temp->A;
 }
int main()
{
int n;
cin>>n;
for(int i=0;i<n;i++)
{
	insert();
	}
	print();	
}
