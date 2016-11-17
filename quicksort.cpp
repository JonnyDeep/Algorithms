#include <bits/stdc++.h>
using namespace std;

/*
*三种快速排序,最基本的快速排序，迪杰斯特拉快速排序（适合相同关键字多的），Dual_pivot快速排序
*
*/
struct double_pointer
{
	int x;
	int y;
};

template<typename Type>
void Exch(Type *arr,int a,int b)
{
	Type temp;
	temp=arr[a];
	arr[a]=arr[b];
	arr[b]=temp;
}

template<typename Type>
void shuffle(Type *arr,int length)
{	
	srand(time(NULL));
	float *aux=new float[length];
	for(int i=0;i<length;i++)
	{
		aux[i]=rand()%999/float(1000);
	}


	for(int i=0;i<length;i++)
	{
		for(int j=i;j>0;j--)
		{
			if(aux[j]<aux[j-1])
			{
				Exch(aux,j,j-1);
				Exch(arr,j,j-1);
			}
		}
	}
}


template<typename Type>
int partition(Type *a,int lo,int hi)
{
	int i=lo+1;
	int j=hi;

	while(i<=j)
	{
		while(a[i]<a[lo])
			i++;
		while(a[j]>a[lo])
			j--;
	
		if(i<j){
			Exch(a,i,j);
		}
		
		if(i==j)
			break;
		
	}

	Exch(a,lo,j);
	return j;
}

template<typename Type>
int partition_1(Type *a,int lo,int hi)
{
	int i=lo-1;
	int j=lo;
	for(;j<hi;j++)
	{
		if(a[j]<a[hi])
		{
			i++;
			Exch(a,i,j);
		}
	}

	Exch(a,i+1,hi);
	return i+1;
}
template<typename Type>
void sort(Type *arr,int lo,int hi)
{
	if(hi<=lo) return;
	int j=partition_1(arr,lo,hi);
	
	sort(arr,lo,j-1);
	sort(arr,j+1,hi);
}

template<typename Type>
void sort(Type *arr,int length)
{
	// shuffle(arr,length);
	sort(arr,0,length-1);
}

template<typename Type>
double_pointer PartitioningDijkstra(Type *a,int lo,int hi)
{
	int lt=lo;
	int gt=hi;
	Type v=a[lo];
	int i=lo;
	while(i<=gt){
		if(a[i]<v){
			Exch(a,lt++,i++);
		}else if(a[i]>v){
			Exch(a,gt--,i);
		}else{
			i++;
		}
	}
	double_pointer dp;
	dp.x=lt;
	dp.y=gt;
	return dp;
}

template<typename Type>
void DijkstraSort(Type *a,int lo,int hi)
{
	if(hi<=lo)
		return;
	double_pointer pt=PartitioningDijkstra(a,lo,hi);
	DijkstraSort(a,lo,pt.x-1);
	DijkstraSort(a,pt.y+1,hi);
}

template<typename Type>
double_pointer Dual_pivot_partition(Type *a,int lo,int hi)
{
	if(a[lo]>a[hi])
		Exch(a,lo,hi);
	int i=lo+1;
	int lt=i;
	int gt=hi-1;
	while(i<=gt)
	{
		if(a[i]<a[lo])
			Exch(a,i++,lt++);
		else if(a[i]>a[hi])
			Exch(a,i,gt--);
		else
			i++;
	}
	Exch(a,lo,--lt);
	Exch(a,++gt,hi);
	double_pointer dp;
	dp.x=lt;
	dp.y=gt;
	return dp;

}

template<typename Type>
void Dual_pivot_sort(Type *a,int lo,int hi)
{
	if(hi<=lo)
		return;
	double_pointer pt=Dual_pivot_partition(a,lo,hi);
	Dual_pivot_sort(a,lo,pt.x-1);
	Dual_pivot_sort(a,pt.x+1,pt.y-1);
	Dual_pivot_sort(a,pt.y+1,hi);
}
int main()
{

	char a[]={'K','R','A','T','E','L','E','P','U','I','M','Q','C','X','O','S'};
	// char b[]={'E','C','A','I','E'};
	// char c[]={'E','C','A'};
	// char d[]={'A','C'};
	// // char e[]={'P','U','T','M','Q','R','X','O','S'};
	// int f[]={'2','8','7','1','3','5','6','4'};
	// cout<<partition_1(f,0,7);
	// cout<<partition_1(a,0,15);
	// cout<<partition_1(b,0,4);
	// cout<<partition_1(c,0,2);
	// cout<<partition_1(d,0,1);
	// cout<<partition_1(e,0,8);
	// DijkstraSort(a,0,15);
	Dual_pivot_sort(a,0,15);
	for(int i=0;i<16;i++)
	{
		cout<<a[i]<<' ';
	}


	// char g[]={'P','A','B','X','W','P','P','V','P','D','P','C','Y','Z'};
	// double_pointer pt=PartitioningDijkstra(g,0,13);
	// cout<<pt.x<<' '<<pt.y<<endl;
	// char M[]={'S','E','A','Y','R','L','F','V','Z','Q','T','C','M','K'};
	// double_pointer pt=Dual_pivot_partition(M,0,13);
	// cout<<pt.x<<' '<<pt.y<<endl;
	return 0;
}