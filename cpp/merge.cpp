#include <iostream>
using namespace std;
void merge(int arrl[],int arrR[],int arr[],int l,int r)
{
	int i=0;
	int j=0;
	int k=0;
	while(i<l && j<r)
	{
		if(arrl[i]>=arrR[j])
		{
			arr[k]=arrR[j];
			j++;
		}
		else{
			arr[k]=arrl[i];
			i++;
		}
		k++;
	}
	while(i<l)
	{
		arr[k]=arrl[i];
		k++;
		i++;
	}
	while(j<r)
	{
		arr[k]=arrR[j];
		k++;
		j++;
	}
}
void mergesort(int arr[],int n)
{
	if(n<2)
	{
		return;
	}
	int mid=n/2;
	int i;
	int arrleft[mid];
	int arrright[n-mid];
	for(i=0;i<mid;i++)
	{
		arrleft[i]=arr[i];
	}
	for(i=mid;i<n;i++)
	{
		arrright[i-mid]=arr[i];
	}
	mergesort(arrleft,mid);
	mergesort(arrright,n-mid);
	merge(arrleft,arrright,arr,mid,n-mid);
}
void swap(int *n1,int *n2)
{
	int temp=*n1;
	*n1= *n2;
	*n2=temp;
}
int partition(int arr[],int start,int end)
{
	int pivot=arr[end];
	int pindex=start;
	for(int i=start;i<end;i++)
	{
	   if(arr[i]<=pivot)
	   {
	      swap(arr[pindex],arr[i]);
		  pindex++;   	
	   }	
	}
	swap(arr[pindex],arr[end]);
	return pindex;
}
void quicksort(int arr[],int start,int end)
{
	if(start<end){
    int pindex=partition(arr,start,end);
    quicksort(arr,start,pindex-1);
    quicksort(arr,pindex+1,end);  
}
}

int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	mergesort(arr,n);
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	
	int k;
	cin>>k;
	int arr1[k];
	for(int i=0;i<k;i++)
	{
		cin>>arr1[i];
	}
	quicksort(arr1,0,k-1);
	for(int i=0;i<k;i++)
	{
		cout<<arr1[i]<<" ";
	}
	
}
