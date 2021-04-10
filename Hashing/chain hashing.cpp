#include<iostream>
#include<vector>
using namespace std;
class hash{
	public:
		int n;
		vector<vector<int> >A;
		hash(int n)
		{
			A=vector<vector<int> >(n); //set size of 2D vector in class
			this->n=n;		
		}
		int index(int value)// setting index
		{
			return value%n;
		}
		void insert(int value)
		{
			A[index(value)].push_back(value);
		}
		void deletet(int value)
		{
			int iindex=index(value);
			for(int j=0;j<A[iindex].size();j++)
			{
				if(value==A[iindex][j])
				{
					A[iindex].erase(A[iindex].begin()+j);
					break;
				}
			}
		}
		void display()
		{
			for(int i=0;i<A.size();i++)
			{
				cout<<i;
				for(int j=0;j<A[i].size();j++)
				{
					cout<<"->"<<A[i][j];
				}
				cout<<endl;
			}
		}
};
int main()
{
	cout<<"Enter Number of element";
	int n,a;
	cin>>n;
	hash H(n);
	for(int i=0;i<n;i++)
	{
		cin>>a;
		H.insert(a);
	}
	cout<<endl<<endl;
	H.display();
	H.deletet(55);
	H.display();
}
