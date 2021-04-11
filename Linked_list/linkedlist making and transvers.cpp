/*
 *
 *
 ////*** this code is for creating node and insert data
 ////*** after insertion display of node data
 ////*** deletion of node by entering number of node
 *
 *
 */ 
 // this code is for singly linked list
#include<iostream>
#include<conio.h>
using namespace std;
    class node{    //node create by using class

	public:// public usable
		int data;// data storing part 
		node *next;// pointer for pointing next node
    };
node* createnode(){  //function for creating new node
   node *temp;  
   temp=new node;
   return temp; // returning the address of new node 
}
node* insertdata(node* head)// finction for inserting data with take and return nature of node
{
	node *temp1;
	temp1=createnode();// address of created node
	cout<<"Enter number:-";
	cin>>temp1->data;// data entering
	temp1->next=NULL; // pointing the pointer to null so it didnt create garbage
	if(head==NULL) // if taked note is null then the null node filled by new node 
	{
		head=temp1;
	}
	else// if taked node is note null
	{
		node *temp;
		temp=head;
		while(temp->next!=NULL) // checking which node pointing part is null 
		{
			temp=temp->next;// if pointing part is not null changing  the temp address
		}
		temp->next=temp1;// after finding the the which pointing  null change the null pointing to new node pointing
	}
	return head;// here we returing head because in starting we passed a null pointer(agar null pointer pass krte h toh jaha se pass ho rha h waha update nhi hoga isliye hum return bhi kr rhe h  data
}
void display(node *head)// function taking node head for dispkay data in all node
{
	cout<<"Entered Number are as follow:"<<endl;
	node *temp;
	temp=head;// head address passes to tempary pointer which adress change and help in printing data
	while(temp!=NULL)// checking when the pointer become null break the loop
	 { 
		cout<<temp->data<<endl;// if temp is not null print data of data pointer which node
		temp=temp->next;// after prtinting change the address of temp to next node which temp is pointing
	 }
    
}
int sizelist(node *head)// function for counting number of node in our linked list
{
	node *temp;
	temp=head;
	int count=0;
	while(temp!=NULL)// if temp is not break the loop
	 { 
		count++;
		temp=temp->next;// changing the temp pointing address
	 }
	 return count;// returning the count of nodes
}
node* delete_node(node* head,int n)// function for deleting node taking head  of list node and position of node
{
	int size;
	size=sizelist(head);// calling function for size of list
	if(n>size)// if enter posituon is greater then the size of list
	{
		cout<<endl<<"Given node Number didnt exist :("<<endl;
		return head;
	}
	else
	{
		if(n==1)// when entered position is first
		{
			node *temp;
			temp=head;// taking address of head
			head=temp->next;// changing address of head to which the head pointing the next node
			delete temp;// deleting first node
			return head;// returning the updated list
		}
		else if(n==size)// when entered position is last
		{
			node *temp,*newnode;
			temp=head;//taking address of head
			while(temp->next!=NULL)// finding the last node which pointing null node
			{
				newnode=temp;// storing the address of previous note
				temp=temp->next;
			}
			delete temp;
			newnode->next=NULL;// after deleting last node making the updated last node to pointing null node
			return head;// returning updated node
		}
		else// when the entered poistion nor the first nither last
		{
		node *temp,*newnode;
			temp=head;//taking address of head
			int i=1;// starting the with first node
			while(i<n)// finding the node which is privious of the node which we wanna delete 
			{
				newnode=temp;// storing the address of one back node after temp which pointing the other node
				temp=temp->next;// temp pointing other node which is +1 of newnode
				i++;// increasing node
				}
				newnode->next=temp->next;// taking the address of deleted note which pointing next node to the node(next)which is privious node of deleted node one
				delete temp;// deleting the given position node
				return head;// returnig the updated node	
		}
	}
}
node *insertnew(node *head,int p,int n)
{
	int size;
	size=sizelist(head);
   if(p>size)
   {
   	node *temp,*newnode;
   	temp=head;
   	newnode=createnode();
   	newnode->data=n;
   	newnode->next=NULL;
   	while(temp->next!=NULL)
   	{
   		temp=temp->next;
	   }
	   temp->next=newnode;
	   return head;
   }
   else if(p==1)
   {
   	node *temp;
   	temp=head;
   	head=createnode();
   	head->data=n;
   	head->next=temp;
   	return head;
   }
   else
   {
   	node *temp,*newnode;
   	int i=1;
   	temp=head;
   	while(i<n)
   	{
   		newnode=temp;
   		temp=temp->next;
   		i++;
	   }
   	node *temp2;
   	temp2=createnode();
   	temp2->data=n;
   	temp2->next=temp;
   	newnode->next=temp2;
   	return head;
   }
 } 
int main()
{ int n;
	node *head=NULL;
   yup:
   	cout<<"Enter the number of entry:";
	cin>>n;
	for(int i=1;i<=n;i++)
	{
	head=insertdata(head);
	}
	char c;
	
	cout<<"if u want to enter more Number press X other vise B:-";
	cin>>c;
	if(c=='X')
	{
		goto yup;
	}
	display(head);
	HP:
	cout<<endl<<"Enter the node number which you want to delete:-";
	int y;
	cin>>y;
	head=delete_node(head,y);
	display(head);
	cout<<"\n If you want to delete another number press X else B:-";
	char j;
	cin>>j;
	if(j=='X')
	{
		goto HP;
	}
	int p,T;
	cout<<"\n\n Position at which you enter data:-";
	cin>>p;
	cout<<"Enter your data:-";
	cin>>T;
	head=insertnew(head,p,T);
	display(head);
	getch();
}
