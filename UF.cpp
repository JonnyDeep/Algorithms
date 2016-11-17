#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <fstream>
using namespace std;

#define BUFF_SIZE 100
#define charToInt(x) x-'0'
struct point
{
	int p;
	int q;
};

class QuickFindUF
{
private:
	int Num;
	int id[100];
public:
	QuickFindUF(int N):Num(N){
		//构造函数，包含N个对象0~N-1
		for(int i=0;i<N;i++)
		{
			id[i]=i;
		}
	}
	void getNum(){cout<<"Num:"<<Num<<endl;}
	void setNum(int N){Num=N;}
	// ~UF();
	void union_1(int p ,int q);
	bool connected(int p,int q);
	int find(int p);
	int count();
	void printUF();
};

void QuickFindUF::printUF()
{
	for(int i=0;i<Num;i++)
	{
		cout<<i<<' ';
	}
	cout<<endl;
	for(int i=0;i<Num;i++)
	{
		cout<<id[i]<<' ';
	}
	cout<<endl;
}
bool QuickFindUF::connected(int p,int q){
	return id[p]==id[q];
}

int QuickFindUF::count(){
	return Num;
}

void QuickFindUF::union_1(int p,int q){
	if(id[p]!=id[q]){
		for(int i=0;i<Num;i++)
		{
			if(id[i]==id[p])
			{
				id[i]=id[q];
			}
		}
	}
}


class QuickUnionUF{
private:
	int Num;
	int *id;
public:
	QuickUnionUF(int N):Num(N){
		id=new int[Num];
		for (int i = 0; i < Num; ++i)
		{
			/* code */
			id[i]=i;
		}
	}
	bool connected(int p,int q);
	void union_1(int p,int q);

private:
	int root(int i);
};


int QuickUnionUF::root(int i){
	while(i!=id[i])
	{
		i=id[i];
	}
	return i;
}

bool QuickUnionUF::connected(int p,int q){
	return root(p)==root(q);
}

void QuickUnionUF::union_1(int p,int q){
	int i = root(p);
	int j = root(q);
	id[i] = j;
}

class QuickUnionUF_Weight{
private:
	int Num;
	int *id;
	int *sz;
public:
	QuickUnionUF_Weight(int N):Num(N){
		id=new int[Num];
		sz=new int[Num];
		for (int i = 0; i < Num; ++i)
		{
			/* code */
			id[i]=i;
			sz[i]=1;
		}
	}
	bool connected(int p,int q);
	void union_1(int p,int q);

private:
	int root(int i);
};


int QuickUnionUF_Weight::root(int i){
	while(i!=id[i])
	{
		id[i]=id[id[i]];
		i=id[i];
	}
	return i;
}

bool QuickUnionUF_Weight::connected(int p,int q){
	return root(p)==root(q);
}

void QuickUnionUF_Weight::union_1(int p,int q){
	int i = root(p);
	int j = root(q);
	if(sz[i]<sz[j])
	{
		id[i]=j;
		sz[j]+=sz[i];
	}else{
		id[j]=i;
		sz[i]+=sz[j];
	}
}
int main_1(int argc, char const *argv[])
{
	/* code */
	cout<<"hello union"<<endl;
	char buff[BUFF_SIZE]={'0'};
	ifstream in;
	in.open("tinyUF.txt");
	in.getline(buff,BUFF_SIZE);
	int N=atoi(buff);
	cout<<N<<endl;
	QuickFindUF uf(N);
	while(in.getline(buff,BUFF_SIZE))
	{
		int p = charToInt(buff[0]);
		int q = charToInt(buff[2]);

		if(!uf.connected(p,q))
		{

			uf.union_1(p,q);
			cout<<p<<" "<<q<<endl;
		}
	}
	in.close();
	
	// system("pause");
	cout<<4<<' '<<3<<endl;
	if(uf.connected(4,3))
	{
		cout<<"connected"<<endl;
	}else{
		cout<<"not connected"<<endl;
	}
	// uf.printUF();
	cin.get();
	return 0;
}

int main(int argc, char const *argv[])
{
	/* code */
	ifstream in;
	in.open("tinyUF.txt");
	char buff[BUFF_SIZE];
	in.getline(buff,BUFF_SIZE);
	int N=atoi(buff);
	point *pt=new point[N];
	int it=0;
	while(it<N)
	{
		in.getline(buff,BUFF_SIZE);
		pt[it].p=charToInt(buff[0]);
		pt[it].q=charToInt(buff[2]);
		it++;
	}

	QuickUnionUF uf(N);
	for(int i=0;i<N;i++)
	{
		if(!uf.connected(pt[i].p,pt[i].q))
		{
			uf.union_1(pt[i].p,pt[i].q);
		}
	}
	return 0;
}
