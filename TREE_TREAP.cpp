#include<iostream>
#include<time.h>
const int maxn = 100;
using namespace std;

//phien ban xoay
struct node{
	int data;
	int frequent;
	node* left;
	node* right;
	node(int data, int fre){
		this->data = data;
		this->frequent = fre;
		this->left = this->right = NULL;
	}
};

void print_tree(node* root, int h){
	if(root == NULL){
		for(int i = 1; i <= h; i++){
			cout << "    ";
		}
		cout << "     *" << endl;
		return;
	}
	print_tree(root->right, h + 1);
	for(int i = 1; i <= h; i++){
		cout << "    ";
	}
	cout << root->data << ":" << root->frequent << endl;
	print_tree(root->left, h + 1);
}

node* right_rotation(node* root){
	node* x = root->left;
	root->left = x->right;
	x->right = root;
	return x;
}

node* left_rotation(node* root){
	node* x = root->right;
	root->right = x->left;
	x->left = root;
	return x;
}

node* insert_treap(node* root, int data, int fre){
	if(root == NULL){
		return new node(data, fre);
	}
	if(data > root->data){
		root->right = insert_treap(root->right, data, fre);
		if(root->right->frequent > root->frequent){
			root = left_rotation(root);
		}
	}
	else{
		root->left = insert_treap(root->left, data, fre);
		if(root->left->frequent > root->frequent){
			root = right_rotation(root);
		}
	}
	return root;
}

node* delete_node_treap(node* root, int data){
	if(root == NULL){
		return root;
	}
	if(data > root->data){
		root->right = delete_node_treap(root->right, data);
	}
	else if(data < root->data){
		root->left = delete_node_treap(root->left, data);
	}
	else if(root->left == NULL){
		node* x = root->right;
		delete root;
		root = x;
	}
	else if(root->right == NULL){
		node* x = root->left;
		delete root;
		root = x;
	}
	else if(root->left->frequent > root->right->frequent){
		root = right_rotation(root);
		root->right = delete_node_treap(root->right, data);
	}
	else{
		root = left_rotation(root);
		root->left = delete_node_treap(root->left, data);
	}
	return root;
}

//cài đặt theo phiên bản merge and split 
struct TreapNode{ 
	int key , priority;
	TreapNode *left , *right;
	TreapNode(int x){ 
		key = x;
		priority = rand() % 100;
		left = right = NULL; 
	} 
}; 

TreapNode* search(TreapNode* root, int key){ 
	if (root == NULL || root->key == key) 
	return root;
	if (root->key < key) 
	return search(root->right, key); 
	return search(root->left, key); 
}

void Split(TreapNode* root , int x , TreapNode* &l , TreapNode* &r){
	l = r = NULL;
	if(root == NULL) return;//dieu kien co so
	if(root->key < x){
		Split(root->right , x , root->right , r);
		l = root;
	}
	else{
		Split(root->left , x , l , root->left);
		r = root;
	}
}

TreapNode* Merge(TreapNode* l , TreapNode* r){
	if(!l || !r)  return (l ? l : r);	
	if(l->priority > r->priority){
		l->right = Merge(l->right , r);	
		return l;
	}	
	else{
		r->left = Merge(l , r->left);
		return r;
	}
}

TreapNode* insert(TreapNode* root, int key) { 
	TreapNode* l , *r;
	Split(root , key , l , r);	
	return Merge(Merge(l , new TreapNode(key)) , r);
} 

TreapNode* deleteNode(TreapNode* root, int key) {
	TreapNode* l , *r , *m;
	Split(root , key , l , m);	
	Split(m , key + 1 , m , r);	
	if(m && m->key == key && !m->left && !m->right)
	delete m;	
	return Merge(l , r);
} 

void inorder(TreapNode* root) { 
	if (root){ 
		inorder(root->left);
		cout << "key : "<< root->key << " | priority : " << root->priority << endl; 
		inorder(root->right); 
	} 
} 

int main(){
	node* root = NULL;
	//srand((int)time(0));
	root = insert_treap(root, 12, 10);
	root = insert_treap(root, 40, 1);
	root = insert_treap(root, 50, 20);
	root = insert_treap(root, 18, 0);
	root = insert_treap(root, 1, 4);
	root = insert_treap(root, 30, 15);
	root = insert_treap(root, 39, 2);
	print_tree(root, 0);
	cout << endl;
	cout << endl;
	root = delete_node_treap(root, 50);
//	root = insert(root, 12);
//	root = insert(root, 12);
//	root = insert(root, 12);
	print_tree(root, 0);
}