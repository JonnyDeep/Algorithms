#include <bits/stdc++.h>
using namespace std;



template<typename Type>
bool less_elem(Type a,Type b)
{
	if(a>b) return 1;
	if(a<b) return -1;
	if(a==b) return 0;
}

template<typename Type>
void Exch(Type *arr,int i,int j)
{
	Type temp = arr[i];
	arr[i]=arr[j];
	arr[j]=temp;
}

template<typename Type>
Type* Selection_sort(Type *arr,int length)
{
	for (int i = 0; i<length ; ++i)
	{
		/* code */
		int min=i;
		for(int j=i+1;j<length;j++)
		{
			
			if(arr[j]<arr[min])
				min=j;
		}
		Exch(arr,i,min);
	}
}


template<typename Type>
void Shell_sort(Type *arr,int length)
{
	int h=1;
	while(h<length/3) h=3*h+1;

	while(h>=1)
	{
		for(int i=h;i<length;i++)				//插入排序，希尔排序
		{
			for(int j=i;j>=h&&arr[j]<arr[j-h];j-=h)
			{
				Exch(arr,j,j-h);
			}
		}
		h=h/3;
	}
}


template<typename Type>
void Insert_Sort(Type *arr,int length)
{
	for(int i=0;i<length;i++)
	{
		for(int j=i;j>0;j--)
		{
			// if(arr[j]<arr[j-1])
			if(arr[j]<arr[j-1])
			{
				Exch(arr,j,j-1);
			}else{
				break;
			}
			// break;
		}
	}
}

int main(int argc, char const *argv[])
{
	
	char a[]={'s','o','r','t','e','x','a','m','p','l','e'};
	// Selection_sort(a,11);
	Insert_Sort(a,11);
	// Shell_sort(a,11);
	for(int i=0;i<11;i++)
	{
		cout<<a[i]<<' ';
	}
	cout<<endl;
	return 0;
}