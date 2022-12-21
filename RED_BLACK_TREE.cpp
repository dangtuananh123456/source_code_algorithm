#include<iostream>
using namespace std;

struct node{
	int data;
	int color;
	node* left;
	node* right;
	node(int data){
		this->color = 1; //1 is red
		this->right = this->left = NULL;
		this->data = data;
	}
};

void print_tree(node* t, int h){
		if (t == nullptr) {
			for (int i = 0; i < h; i++)
				cout << "   ";
			cout << "  *  " << endl;
			return;
		}
		print_tree(t->right, h + 1);
		for (int i = 0; i < h; i++)
			cout << "   ";
		cout << t->data;
		if(t->color == 1){
			cout << "R   " << endl;
		}
		else{
			cout << "B   " << endl;
		}
		print_tree(t->left, h + 1);
}

node* left_rotation(node* x){
	node* y = x->right;
	x->right = y->left;
	y->left = x;
	swap(x->color, y->color);
	return y;
}

node* right_rotation(node* x){
	node* y = x->left;
	x->left = y->right;
	y->right = x;
	swap(y->color, x->color);
	return y;
}

void flip_color(node* x){
	swap(x->color, x->left->color);
	x->right->color = x->left->color;
}

bool is_red(node* x){
	if(x == NULL){
		return false;
	}
	if(x->color == 1) return true;
	else return false;
}

node* insert(node* x, int data){
	if(x == NULL){
		x = new node(data);
		return x;
	}
	if(data > x->data){
		x->right = insert(x->right, data);
	}
	else{
		x->left = insert(x->left, data);
	}
	if(is_red(x->right) && !is_red(x->left)) x = left_rotation(x);
	if(is_red(x->left) && is_red(x->left->left)) x = right_rotation(x);
	if(is_red(x->right) && is_red(x->left)) flip_color(x);
	return x;
}

node* max_right(node* root){
	if(root->left == NULL) return root;
	return max_right(root->right);
}

node* delete_node(node* root, int data){
	if(root == NULL) return root;
	if(data > root->data){
		root->right = delete_node(root->right, data);
	}
	else if(data < root->data){
		root->left = delete_node(root->left, data);
	}
	else{
		if(root->left == NULL){
			node* x = root->right;
			delete root;
			return x;
		}
		else if(root->right == NULL){
			node* x = root->left;
			delete root;
			return x;
		}
		node* x = max_right(root->left);
		root->data = x->data;
		root->left = delete_node(root->left, root->data);
	}
	if(root == NULL) return root;
	if(is_red(root->right) && !is_red(root->left)) root= left_rotation(root);
	if(is_red(root->left) && is_red(root->left->left)) root = right_rotation(root);
	if(is_red(root->left) && is_red(root->right)) flip_color(root);
	return root;
}

int main(){
	int x;
	cin >> x;
	node* root = NULL;
	for(int i = 1; i <= x; i++){
		int y; cin >> y;
		root = insert(root, y);
		if(root->color == 1){
			root->color = 0;
		}
	}
	print_tree(root, 0);
	cout << endl;
	root = delete_node(root, 25);
	if(root->color == 1) root->color = 0;
	print_tree(root, 0);
}
//10
//10 20 30 40 50 25 21 13 17 19
