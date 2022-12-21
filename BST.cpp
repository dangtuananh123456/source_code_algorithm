#include<iostream>
#include<math.h>
using namespace std;

struct Tree{
	Tree* left;
	Tree* right;
	Tree* parent;
	int data;
	Tree(int data){
		this->data = data;
		this->right = this->left = this->parent = NULL;
	}
};

void print_tree(Tree* t, int h){
		if (t == nullptr) {
			for (int i = 0; i < h; i++)
				cout << "   ";
			cout << "*  " << endl;
			return;
		}
		print_tree(t->right, h + 1);
		for (int i = 0; i < h; i++)
			cout << "   ";
		cout << t->data << endl;
		print_tree(t->left, h + 1);
}

void init_tree(Tree* root){
	root = NULL;
}

Tree* search(Tree* root, int K){
	if(root == NULL){
		return NULL;
	}
	while(root->data != K && root != NULL){
		if(root->data < K) root = root->right;
		else{
			root = root->left;
		}
	}
	return root;
}


void set_link(Tree* Pa, Tree* Chi, bool Inleft){
	if(Chi != NULL) Chi->parent = Pa;
	if(Inleft) Pa->left = Chi;
	else Pa->right = Chi;
}

void insert(Tree* &Root, int K){
	Tree* root = Root;
	Tree* x = new Tree(K);
	Tree* y = NULL;
	while(root != NULL){
		y = root;
		if(root->data > K){
			root = root->left;
		}
		else{
			root = root->right;
		}
	}
	if(y != NULL) set_link(y, x, K < y->data);
	if(Root == NULL){
		Root = x;
	}
}

Tree* max_right(Tree* root){
	Tree* tem;
	while(root != NULL){
		tem = root;
		root  = root->right;
	}
	return tem;
}

Tree* max_left(Tree* root){
	Tree* tem;
	while(root != NULL){
		tem = root;
		root = root->left;
	}
	return tem;
}

void delete_tree(Tree* x, Tree* &root){
	Tree* y;
	if(x->left != NULL && x->right != NULL){
		y = max_right(x->left); // node cực phải của cây con trái
		x->data = y->data; //chuyển data của y lên x;
		x = y;
	}
	Tree* z = x->parent;
	if(x->left == NULL){
		y = x->right;
	}
	else if(x->right == NULL){
		y = x->left;
	}
	set_link(z, y, z->left == x);
	if(root == x) root = y;
	delete x;
}

void left_rotation(Tree* &x, Tree* &root){
	Tree* parent = x->parent;
	Tree* y = x->right;
	Tree* branch = y->left;
	if(branch != NULL && x != NULL) set_link(x, branch, false);
	else x->right = NULL;
	if(y != NULL && x != NULL) set_link(y, x, true);
	if(parent != NULL && y != NULL) set_link(parent, y, parent->left == x);
	else y->parent = NULL;
	if(root == x) root = y;
	x = y;
}

void  right_rotation(Tree* &x, Tree* &root){
	Tree* parent = x->parent;
	Tree* y = x->left;
	Tree* branch = y->right;
	if(branch != NULL && x != NULL) set_link(x, branch, true);//cho con phai cua con trai x tro thanh con trai x
	else{
		x->left = NULL;
	}
	if(y != NULL && x != NULL) set_link(y, x, false); // cho x la con phai cua con trai x
	if(parent != NULL && y != NULL) set_link(parent, y, parent->left == x); // cho con trai x len thay nut x
	else y->parent = NULL;
	if(root == x) root = y;
	x = y;
}

void make_backbone(Tree* &root){
	Tree* x = root;
	while(x != NULL){
		while(x->left != NULL){
			right_rotation(x, root);
		}
		x = x->right;
	}
}

int get_perfect_treenode(int node){
	int i = 0;
	int perfectcount = 0;
	while(perfectcount < node){
		i++;
		perfectcount = pow(2, i) - 1;
	}
	return pow(2, i - 1) - 1;
}

void balance_backbone(Tree* &root, int node){
	int internode = get_perfect_treenode(node);
	int extranode = node - internode;
	int i = 0;
	Tree* current = root;
	while(i < extranode){
		i++;
		left_rotation(current, root);
		current = current->right;
	}
	while(internode > 0){
		internode = internode/2;
		i = 0; 
		current = root;
		while(i < internode){
			left_rotation(current, root);
			current = current->right;
			i++;
		}
	}
}

void inordered(Tree* root){
	if(root == NULL) return;
	inordered(root->left);
	cout << root->data << " ";
	inordered(root->right);
}

void preordered(Tree* root){
	if(root == NULL) return;
	cout << root->data << "  ";
	preordered(root->left);
	preordered(root->right);
}
int main(){
	Tree* root = NULL;
	for(int i = 1; i <= 12; i++){
		int x;
		cin >> x;
		insert(root, x);
	} 
	print_tree(root, 0); 
	cout << endl;
	delete_tree(search(root, 7), root);
	print_tree(root, 0);
}


//#include<iostream>
//#include<math.h>
//using namespace std;
//struct node{
//	int data;
//	node* left, *right;
//	node(int data){
//		this->data = data;
//		this->left = this->right = NULL;
//	}
//};
//
//node* insert(node* root, int data){
//	if(root == NULL) return new node(data);
//	if(data > root->data) root->right = insert(root->right, data);
//	else root->left = insert(root->left, data);
//	return root;
//}
//
//node* right_rotation(node* root){
//	node* x = root->left;
//	root->left = x->right;
//	x->right = root;
//	return x;
//}
//
//node* left_rotation(node* root){
//	node* x = root->right;
//	root->right = x->left;
//	x->left = root;
//	return x;
//}
//
//int count_node(node* root){
//	if(root == NULL) return 0;
//	return 1 + count_node(root->right) + count_node(root->left);
//}
//
//void create_backbone(node* &root){
//	if(root == NULL) return;
//	if(root->left != NULL){
//		root = right_rotation(root);
//		create_backbone(root);
//	}
//	else create_backbone(root->right);
//}
//
//void rotate_mtimes(node* &root, int m){
//	if(m == 0) return;
//	root = left_rotation(root);
//	rotate_mtimes(root->right, m - 1);
//}
//
//void create_complete_tree(node* &root){
//	int n = count_node(root);
//	int m = pow(2, floor(log2(n + 1))) - 1;
//	//tao khung cay
//	create_backbone(root);
//	//n - m left_rotation
//	rotate_mtimes(root, n - m);
//	while(m > 1){
//		m /= 2;
//		//m time left_rotation
//		rotate_mtimes(root, m);
//	}
//}
//
//void print_tree(node* root, int h ){
//	if(root == NULL){
//		for(int i = 1; i <= h; i++){
//			cout << "   ";
//		}
//		cout << "*  " << endl;
//		return;
//	}
//	print_tree(root->right, h + 1);
//	for(int i = 1; i <= h; i++){
//		cout << "   ";
//	}
//	cout << root->data << endl;
//	print_tree(root->left, h + 1);
//}
//
//int main(){
//	node* root = NULL;
//	for(int i = 1; i <= 15; i++){
//		int x; cin >> x;
//		root = insert(root, x);
//	}
//	create_complete_tree(root);
//	print_tree(root, 0);
//}


//6 2 10 5 9 4 8 7 1 0 11 12