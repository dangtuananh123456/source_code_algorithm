#include<iostream>
#include<vector>
using namespace std;

int m, n;
vector<int> adj[1001];
bool check[1001];
int max_length[1001];

void input(){
	cin >> m >> n;
	for(int i = 1; i <= n; i++){
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	max_length[1] = 1;
}
int parent[1001];

void dfs_1(int u){
	check[u] = true;
	for(auto it : adj[u]){
		if(!check[it]){
			parent[it] = u;
			max_length[it] = max_length[u] + 1;
			dfs_1(it);
		}
	}
}

int get_max_element(){
	int max = 0;
	int index = 1;
	for(int i = 1; i <= m; i++){
		if(check[i] && max < max_length[i]){
			max = max_length[i];
			index = i;
		}
	}
	return index;
}

void trace_path(int u, int v){
	while(v != u){
		cout << v << "->";
		v = parent[v];
	}
	cout << u << endl;
}

int main(){
	input();
	dfs_1(1);
	int x = get_max_element();
	memset(check, false, sizeof(check));
	max_length[x] = 1;
	dfs_1(x);
	int y = get_max_element();
	trace_path(x, y);
}
//7 6
//1 2
//1 3
//1 4
//2 5 
//2 6
//4 7