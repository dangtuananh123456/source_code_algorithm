#include<iostream>
#include<stack>
#include<sstream>
#include<vector>
#include<string.h>
using namespace std;

struct node{
	string s;
	node* left;
	node* right;
	node(string s){
		this->left = this->right = NULL;
		this->s = s;
	}
};

void conversion(istream& s){
	string str;
	string post_fix = "";
	stack<string> sta;
	while(s >> str){
		if(str == "(") sta.push(str);
		else if(str == ")"){
			while(sta.top() != "("){
				string tem = sta.top(); sta.pop();
				post_fix += tem;
			}
			sta.pop();
		}
		else if(str == "/" || str == "*" || str == "+" || str == "-" || str == "^"){
			if(str == "+" || str == "-"){
				while(sta.top() != "("){
					string tem = sta.top(); sta.pop();
					post_fix += tem;
				}
			}
			else{
				while(sta.top()  == "/" || sta.top() == "*" || sta.top() == "^"){
					string tem = sta.top(); sta.pop();
					post_fix += tem;
				}
			}
			sta.push(str);
		}
		else post_fix += str;
	}
	
	cout << post_fix << endl;
}

node* make_tree_postfix(istream& ss){
	string str;
	stack<node*> st;
	while(ss >> str){
		if(str == "/" || str == "+" || str == "-" || str == "*" || str == "^"){
			node* curr = new node(str);
			node* x = st.top(); st.pop();
			node* y = st.top(); st.pop();
			curr->left = y;
			curr->right = x;
			st.push(curr);
		}
		else{
			node* curr = new node(str);
			st.push(curr);
		}
	}
	return st.top();
}

node* make_tree_prefix(istream& ss){
	string str;
	stack<node*> st;
	while(ss >> str){
		if(str == "/" || str == "*" || str == "+" || str == "-" || str == "^"){
			node* curr = new node(str);
			st.push(curr);
		}
		else{
			vector<node*> v;
			node* curr = st.top(); st.pop();
			while(curr->left != NULL && curr->right != NULL){
				if(v.size() == 0){
					v.push_back(curr);
				}
				else{
					v.insert(v.begin(), 1, curr);
				}
				curr = st.top(); st.pop();
			}
			if(curr->left == NULL){
				curr->left = new node(str);
			}
			else curr->right = new node(str);
			st.push(curr);
			for(auto it : v){
				st.push(it);
			}
		}
	}
	node* tem = NULL;
	while(!st.empty()){
		tem = st.top(); st.pop();
		if(st.empty()){
			return tem;
		}
		node* tem1 = st.top(); st.pop();
		if(tem1->right == NULL){
			tem1->right = tem;
			st.push(tem1);
		}
		else{
			node* tem2 = st.top(); st.pop();
			tem2->right = tem;
			tem2->left = tem1;
			st.push(tem2);
		}
	}
	return tem;
}

int main(){
	string s = "( ( 6 / 2 + 4 ) * ( 8 - 3 ) + ( 2 ^ 3 + 4 ) )";
	stringstream ss(s);
	conversion(ss);
	system("pause");
} 