#include<iostream>
#include<vector>
#include<algorithm>
#include<stdlib.h>
using namespace std;

struct egde{
	int u, v;
	int w;
};

int m, n;
vector<egde> mts;
int parent[1005], size[1005];

void make_set(){
	for(int i = 0; i < n; i++){
		parent[i] = i;
		size[i] = 1;
	}
}

int find(int a){
	if(a == parent[a]){
		return a;
	}
	return parent[a] = find(parent[a]);
}

bool Union(int a, int b){
	a = find(a);
	b = find(b);
	if(a == b){
		return false;
	}
	if(size[a] < size[b]){
		swap(a,b);
	}
	parent[b] = a;
	size[a] += size[b];
	return true;
}

bool cmp(egde a, egde b){
	return a.w < b.w;
}

void input(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x, y, z;
		cin >> x >> y >> z;
		egde e;
		e.u = x; e.v = y; e.w = z;
		mts.push_back(e);
	}
}

void cruskal(){
	vector<egde> empty;
	int d = 0;
	sort(mts.begin(), mts.end(), cmp);
//	for(auto i : mts){
//		cout << i.u << " " << i.v << " " << i.w << endl;
//	}
	//thuật toán cruskal
	for(int i = 0; i < m; i++){
		if(empty.size() == n-1) break;
		egde e;
		e = mts[i];
		if(Union(e.u, e.v)){
			empty.push_back(e);
			d += e.w;
		}
	}
	// xuất 
	if(empty.size() != n-1){
		cout << "graph don't conected\n";
	}
	else{
		cout << "gia tri nho nhat cua cay nhi phan: " << d;
		cout << endl;
		for(auto i : empty){
			cout << i.u << " " << i.v << " " << i.w << endl;
		}
	}
}

int main(){
	input();
	make_set();
	cruskal();
	return 0;
}

//6 9
//1 2 12
//1 3 4 
//2 3 1
//2 4 5
//2 5 3 
//3 5 2
//4 5 3
//3 6 10
//5 6 8