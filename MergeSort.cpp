#include <bits/stdc++.h>
using namespace std;




template<typename Type>
bool isSorted(Type *a,int lo,int hi)
{
	for(int i=lo;i<hi;i++)
	{
		if(a[i]<=a[i+1])
		{
			continue;
		}else{
			return false;
		}
	}
	return true;
}


template<typename Type>
void MergeSort(Type a,Type aux,int lo,int mid,int hi)
{
	assert(isSorted(a,lo,mid));
	assert(isSorted(a,mid+1,hi));
	for(int i=lo;i<=hi;i++)
	{

		aux[i]=a[i];
	}
	int i=lo;
	int j=mid+1;
	for(int k=lo;k<=hi;k++)
	{
		if(i>mid){
			a[k]=aux[j++]; 
		}else if(j>hi){
			a[k]=aux[i++];
		}else if(aux[i]<=aux[j]){
			a[k]=aux[i++];
		}else{
			a[k]=aux[j++];
		}
	}
	assert(isSorted(a,lo,hi));
}

template<typename Type>
void sort(Type *a,Type *aux,int lo,int hi)
{
	if(hi<=lo)
		return;
	int mid=lo+(hi-lo)/2;
	sort(a,aux,lo,mid);
	sort(a,aux,mid+1,hi);
	if(a[mid]<a[mid]) return;  //当a[mid]<a[mid+1]时,结束归并，说明已经有序了
	MergeSort(a,aux,lo,mid,hi);
}


/*
 *sort_1是不需要递归的归并排序
 *
 */
template<typename Type>
void sort_1(Type *a,int length)
{
	Type *aux=new Type[length];
	for(int sz=1;sz<length;sz+=sz)
	{
		for(int lo=0;lo<length-sz;lo+=sz+sz)
		{
			MergeSort(a,aux,lo,lo+sz-1,min(lo+sz+sz-1,length-1));
		}
	}
}

int main(int argc, char const *argv[])
{
	/* code */


	char a[]={'E','E','G','M','R','A','C','E','R','T'};
	char b[10];
	// MergeSort(a,b,0,4,9);
	// sort(a,b,0,9);
	sort_1(a,10);
	for(int i=0;i<=9;i++)
	{
		cout<<a[i]<<' ';
	}
	cin.get();
	return 0;
}