#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

class binary_search
{
private:
	int length;
	int *arr;
public:
	binary_search(int length,int *arr):length(length)
	{
		this->arr=arr;
	}
	~binary_search(){
		delete arr;
	}
	int search(int elem);
	int sum_3();
	void sort();
	void print();
};
int binary_search::sum_3()
{
	int sum=0;
	int count=0;
	for(int i=0;i<length;i++)
	{
		for(int j=i+1;j<length;j++)
		{

			sum=-(arr[i]+arr[j]);
			if(sum>arr[j]&&search(sum)!=-1)
			{
				count++;
			}
			// cout<<sum<<' '<<arr[j]<<' '<<arr[i]<<' '<<endl;
		}
	}
	return count;
}
void binary_search::print()
{
	for(int i=0;i<length;i++)
	{
		cout<<arr[i]<<' ';
	}

	cout<<endl;
}
void binary_search::sort(){
	for(int i=0;i<length;i++)
	{
		for(int j=0;j<length-i;j++)
		{
			if(arr[j]>arr[j+1]){
				int temp;
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}

int binary_search::search(int elem){
	int low=0;
	int height=length-1;
	while(low<=height){
		int mid=(low+height)/2;
		if(arr[mid]>elem)
			height=mid-1;
		else if(arr[mid]<elem)
			low=mid+1;
		else{
			return mid;
		}
	}

	return -1;
}

int main(int argc, char const *argv[])
{
	char buff[100]={'\0'};
	int elem;

	ifstream in;
	in.open("ints.txt");
	in.getline(buff,100);

	int length=buff[0]-'0';

	buff[0]='\0';
	in.getline(buff,100);
	char temp[4]={'\0'};
	in.close();
	int *arr=new int[length];
	int j=0;
	int k=0;

	for (int i = 0; i < 100; i++)
	{
		if(buff[i]!='\0')
		{
			if(buff[i]!=32)
			{
				temp[j]=buff[i];
				j++;
				
			}else{
				j=0;
				arr[k++]=atoi(temp);
				temp[0]='\0';
				temp[1]='\0';
				temp[2]='\0';
				temp[3]='\0';
				if(k>length)
					break;
				
			}

		}
	
		if(k==length-1){
			arr[k]=atoi(temp);
		}
	}


	binary_search binary(8,arr);
	// binary.print();
	binary.sort();
	// binary.print();
	cout<<binary.sum_3();
	
	cin.get();
	return 0;
}
