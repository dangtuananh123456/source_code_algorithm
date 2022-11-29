#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

//10 8 
//1 7
//1 2
//2 3
//2 4
//3 6
//6 7
//5 8
//8 9
//3 7
int m,n,s,t;
vector<int> adj[1001];
bool visited[1001];
int parent[1001];

//init
void inp(){
	cin >> m >> n >> s >> t;
	for(int i=0; i<n;i++){
		int x,y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	memset(visited,false,sizeof(visited));
	memset(parent,0,sizeof(parent));
}

//dfs
void dfs(int x){
	visited[x] = true;
	for(int a : adj[x]){
		if(!visited[a]){
			parent[a] = x;
			dfs(a);
		}
	}
}

void bfs(int x){
	queue<int> q;
	q.push(x);
	visited[x] = true;
	while(!q.empty()){
		int v = q.front();
		q.pop();
		//visited[v] =true;
		for(int i : adj[v]){
			if(!visited[i]){
				parent[i] = v;
				q.push(i);
				visited[i] =true;
			}
		}
	}
}

void path(){
	bfs(s);
	if(!visited[t]){
		cout << "no way\n";
	}
	else {
		vector<int> v;
		while(t != s){
			v.push_back(t);
			t = parent[t];
		}
		v.push_back(s);
		reverse(v.begin(),v.end());
		for(auto x : v){
			cout << x << " ";
		}
	}
}


int main(){
	inp();
	path();
	return 0;
}