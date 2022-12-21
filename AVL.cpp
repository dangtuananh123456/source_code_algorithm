#include<iostream>
using namespace std;
struct node{
	int data;
	int ht; // chieu cao
	node *left, *right;
	node(int data){
		this->data = data;
		this->ht = 1;
		this->left = this->right = NULL;
	}
};

void print_tree(node* root, int h){
	if(root == NULL){
		for(int i = 1; i <= h; i++){
			cout << "  "; 
		}
		cout << "* " << endl;
		return;
	}
	print_tree(root->right, h + 1);
	for(int i = 1; i <= h; i++){
		cout << "  ";
	}
	cout << root->data << endl;
	print_tree(root->left, h + 1);
}

int get_height(node* root){
	if(root == NULL) return 0;
	return root->ht;
}

int height(node* root){
	if(root == NULL) return 0;
	return 1 + max(get_height(root->right), get_height(root->left));	
}

int balance_factor(node* root){
	if(root == NULL) return 0;
	return get_height(root->left) - get_height(root->right);
}

node* right_rotation(node* root){
	node* x = root->left;
	root->left = x->right;
	x->right = root;
	root->ht = height(root);
	x->ht = height(x);
	return x;
}

node* left_rotation(node* root){
	node* x = root->right;
	root->right = x->left;
	x->left = root;
	root->ht = height(root);
	x->ht = height(x);
	return x;
}

node* left_left(node* root){
	return right_rotation(root);
}

node* right_right(node* root){
	return left_rotation(root);
}

node* right_left(node* root){
	root->right = right_rotation(root->right);
	return left_rotation(root);
}

node* left_right(node* root){
	root->left = left_rotation(root->left);
	return right_rotation(root);
}

node* insert_AVL(node* root, int data){
	if(root == NULL) return new node(data);
	if(data > root->data){
		root->right = insert_AVL(root->right, data);
		if(balance_factor(root) == -2){
			if(balance_factor(root->right) == -1){
				//lech right_right
				root = right_right(root);
			}
			else{
				//right_left
				root = right_left(root);
			}
		}
	}
	else{
		root->left = insert_AVL(root->left, data);
		if(balance_factor(root) == 2){
			if(balance_factor(root->left) == 1){
				//lech left_left
				root = left_left(root);
			}
			else{
				//lech left_right
				root = left_right(root);
			}
		}
	}
	root->ht = height(root);
	return root;
}

node* max_right(node* root){
	if(root->right == NULL) return root;
	return max_right(root->right);
}

node* delete_AVL(node* root, int data){
	if(root == NULL) return root;
	if(data > root->data){
		root->right = delete_AVL(root->right, data);
	}
	else if(data < root->data) root->left = delete_AVL(root->left, data);
	else{
		if(root->left == NULL){
			node* x = root;
			root = root->right;
			delete x;
		}
		else if(root->right == NULL){
			node* x = root;
			root = root->left;
			delete x;
		}
		else{
			node* x = max_right(root->left);
			root->data = x->data;
			root->left = delete_AVL(root->left, root->data);
		}
	}
	if(root == NULL) return root;
	root->ht = height(root);
	if(balance_factor(root) == -2){
		if(balance_factor(root->right ) == -1){
			//lech right_right
			root = right_right(root);
		}
		else{
			root = right_left(root);
		}
	}
	else if(balance_factor(root) == 2){
		if(balance_factor(root->left) == 1){
			root = left_left(root);
		}
		else{
			root = left_right(root);
		}
	}
	return root;
}
int main(){
	node* root = NULL;
	for(int i = 1; i <= 11; i++){
		int x; cin >> x;
		root = insert_AVL(root, x);
	}
	cout << endl;
	print_tree(root, 0);
//	root = delete_AVL(root, 12);
//	root = delete_AVL(root, 8);
//	cout << endl;
//	print_tree(root, 0);
}

//33 14 15 92 64 35 79 27 38 105 99