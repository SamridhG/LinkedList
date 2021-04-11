#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node *prev;
		node *next;
		node(int data)
		{
			this->data=data;
			this->prev=NULL;
			this->next=NULL;
		}
};
node* create(node *head)
{
	int a;
	cin>>a;
	node *current;
current=head;
if(head==NULL)
{
	head=new node(a);
	head->next=head;
	head->prev=head;
}
else
{
	while(current->next!=head)
	{
		current=current->next;
	}
	current->next=new node(a);
	current->next->prev=current;
	current->next->next=head;
	head->prev=current->next;	
}
return head;
}
void display(node *head)
{
	node *current;
	current=head;
	do
	{
		cout<<current->data<<" ";
		current=current->next;
	}while(current!=head);
	cout<<endl;
	do
	{
		cout<<current->prev->data<<" ";
		current=current->prev;
	}while(current!=head);
}
int Size(node *head)
{
	node *current;
	current=head;
	int count=0;
	do
	{
		count++;
		current=current->next;
	}while(current!=head);
	return count;
}
node* insertion(node *head,int position,int data)
{
	if(head==NULL)
	{
		cout<<"system error";
	}
	else
	{	
	if(position==1)
	{
	node *current;
	current=head;
	head=new node(data);
	head->next=current;
	head->prev=current->prev;
	current->prev->next=head;
	current->prev=head;
    }
    else if(position<=Size(head))
    {
    	node *current;
    	current=head;
    	int pos=1;
    	while(pos<position)
    	{
    		pos++;
    		current=current->next;
		}
		node *prevs;
		prevs=current->prev;
		prevs->next=new node(data);
		prevs->next->prev=prevs;
		prevs->next->next=current;
		current->prev=prevs->next;
	}
	else
	{
		node *current,*tail;
		current=head;
		tail=current->prev;
		tail->next=new node(data);
		tail->next->prev=tail;
		tail->next->next=head;
		head->prev=tail->next;
	}

    }
return head; 

}
  node* deletion(node *head,int position)
  {
  	if(head==NULL)
  	{
  		cout<<"System Error";
	  }
	  else
	  {
	  	if(position==1)
	  	{
	  		node *current;
	  		current=head;
	  		head->prev->next=head->next;
	  		head->next->prev=head->prev;
	  		head=head->next;
	  		delete current;
		  }
		  	else if(position<=Size(head))
    {
    	node *current;
    	current=head;
    	int pos=1;
    	while(pos<position)
    	{
    		pos++;
    		current=current->next;
		}
	current->prev->next=current->next;
	current->next->prev=current->prev;
	delete current;
	}
	  }
	  return head;
  }
  node* reverse(node *head)
  {
  	node *temp,*temp2,*temp3;
  	temp=head;
  	temp2=head->prev;
  	while(head->next!=temp)
  	{
  		temp3=head;
  		head=head->next;
  		temp3->next=temp2;
  		temp2=temp3;
  		temp2->prev=head;
	  }
	  head->next=temp2;
	  head->prev=temp;
	  return head;
  }
int main()
{
	int n,i;
	cout<<"Enter:-";
	cin>>n;
	node *head=NULL;
	for(i=1;i<=n;i++)
	{
		head=create(head);
	}
	display(head);
	int data,p;
	cout<<"\nEnter position and Data:";
	cin>>p>>data;
	head=insertion(head,p,data);
	display(head);
	cout<<"\nEnter position of node to delete:";
	cin>>p;
	head=deletion(head,p);
	display(head);
	head=reverse(head);
	cout<<"\nAfter Reverse:\n";
	display(head);
	
}
