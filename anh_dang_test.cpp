#include<iostream>
#include<algorithm>
using namespace std;
int n;
struct node{
	int data;
	node *left, *right;
	node(int data){
		this->data = data;
		this->left = this->right = NULL;
	}
};

node* insert(node* root, int data){
	if(root == NULL ) return new node(data);
	if(data > root->data){
		root->right = insert(root->right, data);
	}
	else root->left = insert(root->left, data);
	return root;
}

int a[1001];

void init(){
	memset(a, 0, sizeof(a));
}

void max_node(node* root, int h){
	if(root == NULL) return;
	a[h]++;
	max_node(root->right, h + 1);
	max_node(root->left, h + 1);
}

void print_tree(node* root, int h){
	if(root == NULL){
		for(int i = 1; i <= h; i++){
			cout << "  ";
		}
		cout << "   *  " << endl;
		return;
	}
	print_tree(root->right, h + 1);
	for(int i = 1; i <= h; i++){
		cout << "  ";
	}
	cout << "  " << root->data << "  " << endl;
	print_tree(root->left, h + 1);
}
int main(){
	node* root = NULL;
	cin >> n;
	for(int i = 1; i <= n; i ++){
		int data; cin >> data;
		root = insert(root, data);
	}
	cout << endl;
	print_tree(root, 0);
	init();
	max_node(root, 0);
	for(int i = 0; i < n; i++){
		cout << i << " : " << a[i] << endl;
	}
}

//10 
//14 17 32 3 4 9 43 2 1 10
