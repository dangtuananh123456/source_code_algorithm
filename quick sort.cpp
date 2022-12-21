#include<iostream>
using namespace std;
struct node{
	int data;
	node *left, *right;
	node(int data){
		this->data = data;
		this->left = this->right = NULL;
	}	
};

node* insert(node* root, int data){
	if(root == NULL){
		return new node(data);
	}
	if(data > root->data){
		root->right = insert(root->right, data);
	}
	else{
		root->left = insert(root->left, data);
	}
	return root;
}

void print_tree(node* root, int h){
	if(root == NULL){
		for(int i = 1; i <= h; i++){
			cout << "   ";
		}
		cout << "  *  " << endl;
		return;
	}
	print_tree(root->right, h + 1);
	for(int i = 1; i <= h; i++){
		cout << "   ";
	}
	cout << "   " << root->data << "   " << endl;
	print_tree(root->left, h + 1);
}

int count_node(node* root){
	if(root == NULL) return 0;
	return 1 + max(count_node(root->left), count_node(root->right));
}

int solve(node* root){
	if(root == NULL) return 0;
	cout <<  root->data << "  ";
	if(count_node(root->left) > count_node(root->right)){
		return root->data + solve(root->left);
	}
	else{
		return root->data + solve(root->right);
	}
}

int max_sum(node* root){
	if(root == NULL) return 0;
	return root->data + max(max_sum(root->right), max_sum(root->left));
}

int main(){
	node* root = NULL;
	for(int i = 1; i <= 16; i++){
		int x; cin >> x;
		root = insert(root, x);
	}
	cout << endl;
	print_tree(root, 0);
	int result = solve(root);
	cout << endl;
	cout << result;
}

//23 15 56 43 12 19 46 90 37 1 9  8 15 4 3 54