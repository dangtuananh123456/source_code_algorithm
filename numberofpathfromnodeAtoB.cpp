#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
int m, n, p, t;
vector<int> adj[1001];
int path[1001];
bool visited[1001];

void input(){
	cin >> m >> n >> p >> t;
	for(int i = 1; i <= n; i++){
		int x, y;
		cin >> x >> y;
		adj[y].push_back(x);
	}
	memset(path, 0, sizeof(path));
	path[p] = 1;
	memset(visited, false, sizeof(visited));
}

int pathnumber(int x){
	visited[x] = true;
	if(x == p) return 1;
	for(int v : adj[x]){
		if(visited[v]){
			path[x] += path[v];
		}
		else {
			int tem = pathnumber(v);
			path[x] += tem;
		}
	}
	return path[x];
}

//6 7 1 6
//1 2
//1 4
//2 3 
//5 2
//3 6
//4 5
//5 3


int main(){
	input();
	int tem = pathnumber(t);
	for(int i = 1; i <= m ; i++){
		cout << path[i] << " ";
	}
	return 0;
}