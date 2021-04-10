#include<iostream>
using namespace std;
class hash{
	public:
		int n;
		int *array;
		hash(int n)
		{
		this->n=n;
		this->array=new int[n];
		call();
		}
		void call()
		{
			for(int i=0;i<n;i++)
			{
				array[i]=0;
			}
		}
		void display()
		{
			for(int i=0;i<n;i++)
			{
				cout<<i<<"->"<<array[i]<<endl;
			}
		}
		void insert(int value)
		{
			int indexx=0;
			while(true)
			{
				int index=(value+indexx)%n;
				if(array[index]==0)
				{
					array[index]=value;
					break;
				}
				else
				{
					indexx++;
				}
			}
		}
		void deletet(int value)
		{
			int indexx=0;
			while(true)
			{
				int index=(value+indexx)%n;
				if(array[index]==value)
				{
					array[index]=0;
					break;
				}
				else
				{
					indexx++;
				}
			}
		}
};
int main()
{
	int n;
   cout<<"Enter hash table sizs>";
   cin>>n;
   hash H(n);
   cout<<"Enter the number of element you want to enter";
   int j,k;
   cin>>j;
   for(int i=0;i<j;i++)
   {
   	cin>>k;
   	H.insert(k);
   }
   cout<<"\n\n";
   H.display();
   cout<<"\n\n";
   cout<<"Enter element to delete>>";
   int p;
   cin>>p;
   H.deletet(p);
   cout<<"\n\n";
   H.display();
   
}
