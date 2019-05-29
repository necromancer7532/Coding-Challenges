
#include <iostream>
using namespace std; 
 
int main()
{
	int m,n,max_index,max;
	int* a = NULL;
	int* val= NULL;
	int* ind = NULL;
	bool* mat= NULL;
	cin>>n;
	for(int i=0;i<n;i++)
	{	
		cin>>m;
		a=new int[m];
		val=new int[m];
		ind=new int[m];
		mat=new bool[m];
		int flag=0;
		max=-2147483648;
		for(int i=1;i<=m;i++)
		{	
			cin>>val[i];
			if(val[i]>=0)
			flag=1;
			if(val[i]<0)
			{	 
				if(val[i]>max)
				max=val[i];
				val[i]=0;
				mat[i]=true; 
			}
			else 
			mat[i]=false;
		} 
		if(flag==0)
		{
		cout<<max;
		}
		a[1]=val[1]; 
		a[2]=val[2]; 
		ind[1]=0; 
		ind[2]=0; 
		max=a[1]; 
		max_index=1; 
		for(int i=3;i<=m;i++)
		{
			a[i]=val[i]+max; 
			ind[i]=max_index; 
			if(a[i-1]>max)
			{ 
				max=a[i-1]; 
				max_index=i-1; 
			}
		}
		if(a[m]>max)
		max_index=m; 
		while(max_index!=0)
		{	 
			if(!mat[max_index])
			cout<<val[max_index]; 
			max_index=ind[max_index]; 
		}
	cout<<endl;
	}
return 0;
} 

