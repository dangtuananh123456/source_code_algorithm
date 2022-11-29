#include<iostream>
#include<vector>
#include<queue>
#define max 10001
using namespace std;
int N, K, u, v;
vector<int> adj[max];
bool visited[max];
int parent[max];


void input(){
	cin >> N >> K;
	parent[K]  = 0;
	memset(visited, false, sizeof(visited));
	for(int i = 1; i <= N - 1; i++){
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	cin >> u >> v;
}

void bfs(int x){
	visited[x] = true;
	queue<int> q;
	q.push(x);
	while(!q.empty()){
		int y = q.front();
		q.pop();
		for(auto it : adj[y]){
			if(!visited[it]){
				q.push(it);
				parent[it] = y;
				visited[it] = true;
			}
		}
	}
}


void solve(int x, int z){
	bfs(K);
	memset(visited, false, sizeof(visited));
	while(x != 0){
		visited[x] = true;
		x = parent[x];
	}
	int y = z;
	while(!visited[y] && parent[y] != 0){
		visited[y] = true;
		y = parent[y];
 	}
 	cout << y;
}

int main(){
	input();
	solve(u, v);
}