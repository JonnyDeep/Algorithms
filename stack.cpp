#include <bits/stdc++.h>
using namespace std;

struct Node
{
	string item;
	Node *next;
};


class stack_hlq
{
private:
	Node *first;
public:
	stack_hlq(){
		first=new Node;
		first->next=NULL;
	}

	~stack_hlq(){
		Node *p,*q;
		p=first;
		q=first->next;
		while(q)
		{
			p=q;
			q=q->next;
			first->next=q;
			delete p;
		}
		delete first;
	}
	void push(string item);
	string pop();
	bool isEmpty();
	int size();
	
};

void stack_hlq::push(string item)
{
	// cout<<item<<endl;
	Node *new_node=new Node;
	new_node->item=item;
	new_node->next=NULL;
	Node *old_first;
	old_first=first;
	first=new_node;
	first->next=old_first;
	// cout<<first->item<<endl;
	// cout<<"old_first"<<' '<<old_first->item<<endl;
	// delete old_first;
}

bool stack_hlq::isEmpty()
{
	return first->next==NULL;
}

int stack_hlq::size()
{
	int count=0;
	Node *p;
	p=first;
	while(p->next)
	{
		p=p->next;
		count++;
	}

	return count;
}
string stack_hlq::pop()
{
	// cout<<first->item<<endl;
	Node pop_node;
	pop_node.item=first->item;
	Node *old_first=first;
	first=first->next;
	delete old_first;
	return pop_node.item;
}

template <typename Type>
class ArrayStack  //无法用于string
{
private:
	int N;
	int length;
	Type *arr;
public:
	ArrayStack():N(0),length(1){
		// arr=(Type*)malloc(sizeof(int)*length); malloc只能分配空间不能调用构造函数，在分配string型会出错
		arr = new Type[length];
	}
	~ArrayStack(){
		N=0;
		length=0;
		delete []arr;
		delete arr;
		arr=NULL;
	}

	void push(Type n)
	{
		if(N==length)
		{
			// arr=(Type*)realloc(arr,sizeof(Type)*2*length); malloc只能分配空间不能调用构造函数，在分配string型会出错

			// cout<<length;
			Type *temp = new Type[2*length];
			
			for(int i=0;i<length;i++)
			{
				temp[i]=arr[i];
			}
			length=2*length;
			delete []arr;
			arr=temp;
		}

		arr[N++]=n;
	}

	Type pop()
	{
		// cout<<N<<endl;
		if(N==length/4)
		{
			arr=shrink(arr,length/2);
			// length=length/2;
		}
		// cout<<N<<' '<<arr[0]<<endl;
		Type elem = arr[--N];
		return elem;
	}


	bool isEmpty()
	{
		return N==0;
	}

	int size()
	{
		return N;
	}

	int getLength()
	{
		return length;
	}
private:
	Type* shrink(Type *temp,int size)
	{
		// Type *temp_arr=(Type *)malloc(sizeof(Type)*size); malloc只能分配空间不能调用构造函数，在分配string型会出错
		Type *temp_arr=new Type[size];
		for(int i=0;i<length/4;i++)
		{
			temp_arr[i]=temp[i];
		}

		
		length=size;
		// cout<<length<<endl;
		// cout<<length<<endl;
		delete []temp;
		return temp_arr;
	}
	
};
int main(int argc, char const *argv[])
{
	cout<<"hello"<<endl;
	stack_hlq s;
	string hlq="huang";
	s.push(hlq);
	// if(!s.isEmpty())
	// {
	// 	cout<<"ok";
	// }
	// cout<<s.pop();
	// cout<<"hello"<<endl;
	s.push("li");
	s.push("qun");
	cout<<s.pop()<<endl;
	cout<<s.pop()<<endl;
	cout<<s.pop()<<endl;

	ArrayStack<int>arr;
	arr.push(1);
	// cout<<arr.getLength()<<' '<<arr.size()<<endl;
	arr.push(2);
	// cout<<arr.getLength()<<' '<<arr.size()<<endl;
	arr.push(3);
	// cout<<arr.getLength()<<' '<<arr.size()<<endl;
	arr.push(4);
	// cout<<arr.getLength()<<' '<<arr.size()<<endl;
	arr.push(5);
	// cout<<arr.getLength()<<' '<<arr.size()<<endl;
	arr.push(6);
	// cout<<arr.getLength()<<' '<<arr.size()<<endl;
	arr.push(7);
	// cout<<arr.getLength()<<' '<<arr.size()<<endl;
	arr.push(8);
	// cout<<arr.getLength()<<' '<<arr.size()<<endl;
	arr.push(9);
	// cout<<arr.getLength()<<' '<<arr.size()<<endl;
	arr.push(10);
	// cout<<arr.getLength()<<' '<<arr.size()<<endl;
	cout<<arr.pop()<<' '<<arr.size()<<' '<<arr.getLength()<<endl;
	cout<<arr.pop()<<' '<<arr.size()<<' '<<arr.getLength()<<endl;
	cout<<arr.pop()<<' '<<arr.size()<<' '<<arr.getLength()<<endl;
	cout<<arr.pop()<<' '<<arr.size()<<' '<<arr.getLength()<<endl;
	cout<<arr.pop()<<' '<<arr.size()<<' '<<arr.getLength()<<endl;
	cout<<arr.pop()<<' '<<arr.size()<<' '<<arr.getLength()<<endl;
	cout<<arr.pop()<<' '<<arr.size()<<' '<<arr.getLength()<<endl;
	cout<<arr.pop()<<' '<<arr.size()<<' '<<arr.getLength()<<endl;
	cout<<arr.pop()<<' '<<arr.size()<<' '<<arr.getLength()<<endl;
	cout<<arr.pop()<<' '<<arr.size()<<' '<<arr.getLength()<<endl;

	ArrayStack<char> arr_1;
	arr_1.push('h');
	arr_1.push('w');
	cout<<arr_1.pop()<<endl;
	cout<<arr_1.pop()<<endl;

	ArrayStack<string> arr_2;
	arr_2.push("hlq");
	arr_2.push("asdfjkasdj");
	arr_2.push("sjdlkfjas");
	cout<<arr_2.pop()<<endl;
	cout<<arr_2.pop()<<endl;
	cout<<arr_2.pop()<<endl;
	cout<<"end";
	cin.get();
	return 0;
}