//  Implementing HEAP SORT

#include <bits/stdc++.h>
#include<iostream>
using namespace std;
#define input(arr, n)  for(int i=0;i<n;i++) cin>>arr[i];
#define output(any)  for(auto i:any)  cout << i<<" ";


void heapify(int arr[],int n,int i)
{
    int largest = i;  //root
    int l = 2 * i + 1;  //left child
    int r = 2 * i + 2;  //right child
    
    if (l < n && arr[l] > arr[largest])
        largest = l;
    
    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapsort(int arr[],int n)
{
    for(int i=n/2-1;i>=0;i--)
        heapify(arr,n,i);
    
    for(int i=n-1;i>=0;i--)
    {
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
}

int main() 
{
    int n;
    cin>>n;
    int arr[n];
    input(arr,n);
    heapsort(arr,n);
    cout<<"Sorted array:\n";
    output(arr);
    cout<<"\n";
	return 0;
}

/*  INPUT 
15
43 64 13 78 864 346 786 456 21 19 8 434 76 270 601

    OUTPUT 
Sorted array:
8 13 19 21 43 64 76 78 270 346 434 456 601 786 864 
*/

/*
Time Complexity
1.Best Case:O(nlog(n))
2.Average Case:O(nlog(n))
3.Worst Case:O(nlog(n))
*/