/*
This code gets the values of binary tree from the user and then convert the binary tree to doubly linked list.
The formed Doubly linked list will have elements in the same order as that of inorder traversal of binary tree. 
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode{
	int value;
	TreeNode* left = NULL;
	TreeNode* right = NULL;
};

TreeNode* newNode(int n){
	TreeNode* t = new TreeNode;
	t->value = n;
	t->left = NULL;
	t->right = NULL;
}

TreeNode* insert(TreeNode* t, queue<TreeNode* > &q, int v){		//This function inserts node into the binary tree
	TreeNode* temp = newNode(v);
	if(v==-1){
		temp = NULL;
	}
	if(t==NULL){
		t = temp;
	}
	else if(q.front()->left==NULL){
		q.front()->left = temp;
	}
	else{
		q.front()->right = temp;
		q.pop();
	}
	q.push(temp);
	return t;
}

TreeNode* make_tree(vector<int> v){		//This function converts given vector into Binary Tree
	queue<TreeNode* > q;
	TreeNode* t = NULL;
	for(int i=0;i<v.size();i++){
		t = insert(t,q,v[i]);
	}
	return t;
}

void print_elements(TreeNode* &T){		//This function prints all the elements of doubly linked list
	TreeNode* temp = T;
	cout<<"The elements of doubly linked list are: ";
	while(temp!=NULL){
		cout<<temp->value<<" ";
		temp = temp->right;
	}
}

void to_dll(TreeNode* T, TreeNode* &temp){		//This function converts Binary tree to doubly linked list
	if(T==NULL){
		return;
	}
	to_dll(T->right,temp);
	T->right = temp;
	
	if(temp!=NULL){
		temp->left = T;
	}
	temp = T;
	to_dll(T->left,temp);
}

void to_doubly_linked_list(TreeNode* T){		
	TreeNode* h = NULL;
	to_dll(T,h);
	print_elements(h);
}

int main(){
	int n;		//number of nodes of binary tree
	cin>>n;
	vector<int> v;
	while(n){		//asking user for elements of Binary tree
		int x;
		cin>>x;
		v.push_back(x);
		n--;
	}
	TreeNode* T = make_tree(v);
	to_doubly_linked_list(T);
	
	return 0;
}

/*
Time Complexity : O(N);
Here if we give following binary tree as input:
	5
   / \
  6   8
 / \ / \
3  4 9  2 
The output will be - 3 6 4 5 9 8 2

Suppose if input binary tree is:
    9
   / \
  8   2
 /   / 
5    4 
The output will be - 5 8 9 4 2
*/
