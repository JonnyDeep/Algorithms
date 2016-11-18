#include <bits/stdc++.h>
using namespace std;

struct Node
{
	
	int value;
	Node *left;
	Node *right;
	int count;
	Node(int value)
	{
		this->value=value;
		left=NULL;
		right=NULL;
		count=0;
	}
};

class binarySearchTree
{
private:
	Node *root;

public:
	binarySearchTree()
	{
		root=NULL;



	}

	void insert(Node* node)  //非递归实现二分搜索树的实现
	{
		if(root==NULL){
			root=node;
			root->count++;
			return;
		}
		Node *cur=root;
		Node *pre_cur;
		node->count++;
		while (cur)
		{
			pre_cur=cur;
			pre_cur->count++;
			cur=node->value>cur->value?cur->right:cur->left;
		}

		if(node->value>pre_cur->value)
		{
			pre_cur->right=node;
		}else{
			pre_cur->left=node;
		}
		
		return;
	}

	void insert(int value)
	{
		this->root=insert_1(value,this->root);
		return;
	}

	int size(Node *node)
	{
		if(node==NULL)
		{
			return 0;
		}else{
			return node->count;
		}
	}
	
	int size()
	{
		return size(this->root);
	}

	bool get_elem(int value)
	{
		return get_elem(value,this->root);
	}

	void getMin()
	{
		cout<<getMin(this->root)->value<<endl;
	}
	void print()
	{
		print(this->root);
	}
	void deleteMin()
	{
		deleteMin(this->root);
	}

	void deleteValue(int value)
	{
		Node *cur=this->root;
		Node *pre_cur=cur;
		while(cur)
		{
			pre_cur=cur;
			if(value>cur->value)
			{
				cur=cur->right;
			}else if(value<cur->value){
				cur=cur->left;
			}else{
				if(cur->left==NULL&&cur->right==NULL)
				{
					pre_cur->left=NULL;
					pre_cur->right=NULL;
					delete cur;
					return;
				}
				
				if(cur->left&&cur->right){
					Node *min=getMin(cur->right);
					swap(min->value,cur->value);
					deleteMin(cur->right);
					return;
				}
				
				if(cur->right==NULL&&cur->left!=NULL)
				{
					if(pre_cur->left==cur)
					{
						pre_cur->left=cur->left;
						delete cur;
						return;
					}else{
						pre_cur->right=cur->left;
						delete cur;
						return;
					}
				}

				if(cur->left==NULL&&cur->right!=NULL)
				{
					if(pre_cur->left==cur)
					{
						pre_cur->left=cur->right;
						delete cur;
						return;
					}else{
						pre_cur->right=cur->right;
						delete cur;
						return;
					}
				}
			}
		}

	}
protected:
	void print(Node *node)
	{
		if(node==NULL)
		{
			return;
		}else{
			cout<<node->value<<' ';
		}

		print(node->left);
		print(node->right);
	}


	Node* insert_1(int value,Node* node)  //递归实现插入
	{
		if(node==NULL)
		{
			node = new Node(value);
			node->count=1;
			return node;
		}

		if(value>node->value)
		{
			node->right=insert_1(value,node->right);
		}else if(value<node->value){
			node->left=insert_1(value,node->left);
		}else{
			node->value=value;
		}
		node->count=1+size(node->left)+size(node->right);
		return node;


	}
	
	bool get_elem(int value,Node *node)  
	{
		if(node==NULL)
		{
			return false;
		}

		if(value>node->value)
		{
			get_elem(value,node->right);
		}else if(value<node->value){
			get_elem(value,node->left);
		}else{
			return true;
		}
	}


	Node* getMin(Node *node)
	{
		Node *cur=node;
		while (cur)
		{
			if(cur->left)
				cur=cur->left;
			else
				break;
		}
		//cout<<cur->value;
		return cur;
	}


	void deleteMin(Node *node)
	{
		Node *cur_pre;
		Node *cur;
		cur_pre=cur=node;
		while (cur->left)
		{
			cur_pre=cur;
			cur_pre->count--;
			cur=cur->left;
		}

		if(cur->right==NULL)
		{
			cur_pre->left=NULL;
			cur_pre->right=NULL;
			delete cur;
			return;
		}

		Node *cur_right=cur->right;
		swap(cur->value,cur->right->value);
		cur->left=NULL;
		cur->right=NULL;
		delete cur->right;
		cur->count--;
		return;

	}

};

int main(){



	binarySearchTree bst;
	/********
	Node node(2);

	bst.insert(&node);
	Node node_1(1);

	bst.insert(&node_1);
	Node node_2(3);
	bst.insert(&node_2);
	*****/

	bst.insert(2);
	bst.insert(1);
	bst.insert(3);
	//bst.print(&node);
	//if(bst.get_elem(1))
	//{
	//	cout<<"true"<<endl;
	//}

	//if(bst.get_elem(2))
	//{
	//	cout<<"true"<<endl;
	//}

	//if(bst.get_elem(3))
	//{
	//	cout<<"true"<<endl;
	//}

	//if(bst.get_elem(4))
	//{
	//	cout<<"true"<<endl;
	//}else{
	//	cout<<"false"<<endl;
	//}


	bst.insert(4);

	return 0;
}