#include<iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void quicksort(int arr[], int l, int r)
{
    if (l >= r)
    {
        return;
    }
    int pivot = arr[r];
    int cnt = l;
    for (int i = l; i <= r; i++)
    {
        if (arr[i] >= pivot)
        {
            swap(&arr[cnt], &arr[i]);
            cnt++;
        }
    }
    
    quicksort(arr, l, cnt-2);
    quicksort(arr, cnt, r); 
}
int main()
{
	int r,c,n;
	cin>>n;
	int* row;
	int* col;
	for(int i=0;i<n;i++)
	{
		cin>>r>>c;
		row=new int[r];
		col=new int[c];
		int sum1=0;
		int sum2=0;
		for(int j=0;j<r;j++)
		{
			cin>>row[j];
			sum1+=row[j];
		}
		for(int j=0;j<c;j++)
		{
			cin>>col[j];
			sum2+=col[j];
		}		
	if(sum1!=sum2)
		{
			cout<<"NO"<<endl;
			continue;
		}
	quicksort(row,0,r);
	quicksort(col,0,c);
	int a[r][c];
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			a[i][j]=0;
	for(int i=0;i<r;i++)
		for(int j=0;j<row[i];j++)
			a[i][j]=1;
	int flag=0;
	for(int i=0;i<c;i++)
	{
		sum1=0;
		for(int j=0;j<r;j++)
			sum1+=a[j][i];
		if(sum1!=col[i])
			flag=1;
	}
	if(flag==0)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
		
	}
return 0;
}
	