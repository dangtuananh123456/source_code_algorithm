#include<iostream>
#include<vector>
using namespace std;
int m, n;
vector<int> adj[1001];
int count[1001];
bool visited[1001];
int ans = 0;

void input(){
	cin >> m >> n;
	for(int i = 1; i <= n; i++){
		int x, y; 
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	memset(count, 0, sizeof(count));
}

void DFS(int u, int e){
	cout << u << " ";
	for(auto s : adj[u]){
		if(s != e){
			DFS(s, u);
		}
	}
}

void countnodesubtree(int s, int u){
	count[s] = 1;
	for(auto x : adj[s]){
		if(x != u){
			countnodesubtree(x, s);
			count[s] += count[x];
		}
	}
}
//8 7
//1 2
//1 3 
//1 4
//2 5
//2 6 
//6 8
//4 7

//even tree
int eventree(int x){
	int vertex = 0;
	visited[x] = true;
	for(auto it : adj[x]){
		if(!visited[it]){
			int nodes = eventree(it);
			if(nodes % 2 == 0) ans++;
			else vertex += nodes;
		}
	}
	return vertex + 1;
}

//even tree 2
int eventree2(int x){
	count[x] = 0;
	visited[x] = true;
	for(auto it : adj[x]){
		if(!visited[it]){
			int node = eventree2(it);
			count[x] += node;
		}
	}
	return count[x] + 1;
}
int main(){
	input();
	int x = eventree2(1);
	for(int i = 1; i <= m; i++){
		cout << i << " : " << count[i];
		cout << endl;
	}
	return 0;
}