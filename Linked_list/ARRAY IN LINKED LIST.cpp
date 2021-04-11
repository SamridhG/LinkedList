#include<iostream>
#include<vector>
using namespace std;
class NODE{
	public:
		vector<int> array;
		NODE *next;
		NODE(vector<int>A){
			this->array=A;
			this->next=NULL;
		}
};
NODE* create_node(vector<int>A)
{
	NODE *node;
	node=new NODE(A);
	return node;
}
NODE *insert_node(NODE* node,int size)
{
	cout<<"\nENTER ALL THE ELEMENT:-\n";
    vector<int>A;
    for(int i=0;i<size;i++)
    {
    	int b;
    	cin>>b;
    	A.push_back(b);
	}
	NODE *temp,*temp2;
	temp=node;
	if(node==NULL)
	{
		node=create_node(A);
	}
	else
	{
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=create_node(A);
	}
	A.clear();
	return node;
}
void display(NODE* node)
{
	NODE*temp;
	temp=node;
	while(temp!=NULL)
	{
	 for(int i=0;i<temp->array.size();i++)
	 {
	 	cout<<temp->array[i]<<" ";
	 }
	 cout<<"\n";
	 temp=temp->next;
	}
}
int main()
{
	
	NODE *node=NULL;
	int size;
	cout<<"ENTER THE SIZE OF ARRAY:-";
	cin>>size;
	node=insert_node(node,size);
	display(node);
	cout<<"ENTER THE SIZE OF ARRAY:-";
	cin>>size;
	node=insert_node(node,size);
	display(node);

}
