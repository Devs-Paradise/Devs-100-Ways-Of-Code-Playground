/*Implement Selection Sort*/

#include <iostream>
using namespace std;


void print(int a[],int n)
{
 for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
}


void Selection_Sort(int a[],int n)
{
	int min,pos;
	for(int i=0;i<n-1;i++)
	{
		min=a[i];
		pos=i;
		for(int j=i+1;j<n;j++)
		{
			if(min>a[j])
			{
				//Storing minimum elemet and it's index'
				min=a[j];
				pos=j;
			}
		}
		
		//Swapping ith value with minimum element
		if(pos!=i)
		{
			a[pos]=a[i];
			a[i]=min;
		}
	}
}

int main()
{
 int n;
 cout<<"Enter the size of Array:";
 cin>>n;
 
 int a[n];
 cout<<"Enter the values in Array"<<endl;
 
 for(int i=0;i<n;i++)
    cin>>a[i];
    
 Selection_Sort(a,n);
 print(a,n);
    
 return 0;
}
