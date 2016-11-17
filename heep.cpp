#include <bits/stdc++.h>
using namespace std;

template<typename Type>
class Heap
{
private:
	Type *arr;
	int N;
	int cur;
	inline int left(int i) {return i << 1;}
	inline int right(int i) {return (i << 1) + 1;}
	inline int parent(int i) { return i >> 1;}
public:
	Heap(int N=100):N(N){
		arr = new Type[N+1];
		cur = 0;
	}
	~Heap(){
		if(arr!=NULL){
			delete []arr;
		}
		cur=0;
		N=100;
	}

	/*
	*swim用来在插入时，将大的元素升上去
	*/
	void swim(int k)
	{
		while(k>1&&arr[parent(k)]<arr[k]){
			swap(arr[parent(k)],arr[k]);
			k=parent(k);
		}
	}


	void insert(Type elem){
		arr[++cur]=elem;
		swim(cur);
	}

	/*
	*sink用来在删除元素时，将小的元素沉下去
	*/
	void sink(int k){
		while(left(k)<(cur+1)){
			int j=left(k);
			if(j<(cur+1)&&arr[left(k)]<arr[right(k)]){
				j=right(k);
				// cout<<j<<endl;
			}
			// cout<<arr[k]<<' '<<arr[j]<<endl;
			if(!(arr[k]<arr[j])) {
				// cout<<"hello"<<endl;
				break;

			}
			swap(arr[k],arr[j]);
			k=j;
		}
	}


	Type delMax()
	{
		int max=arr[1];
		swap(arr[1],arr[cur--]);
		// print();
		// cout<<cur<<endl;
		arr[cur+1]=-1;
		sink(1);
		// cur--;
		// print();
		return max;
	}

	void sort()
	{
		while(cur>=1)
		{
			cout<<delMax()<<' ';
		}
	}
	void print(){
		for (int i = 1; i <= cur; ++i)
		{
			/* code */
			cout<<arr[i]<<' ';
		}
		cout<<endl;
	}
};


int main()
{
	Heap<char> h;
	h.insert('a');
	h.insert('b');
	h.insert('c');


	Heap<int> g;
	g.insert(1);
	g.insert(2);
	g.insert(3);
	g.insert(4);
	g.insert(5);
	g.print();
	// g.delMax();
	g.sort();
	// cout<<g.delMax()<<endl;
	// g.print();
	// cout<<g.delMax()<<endl;
	// g.print();
	// cout<<g.delMax()<<endl;
	// g.print();
	// cout<<g.delMax()<<endl;
	// g.print();
	// cout<<g.delMax()<<endl;
	// g.print();
	// g.print();
	return 0;
}