#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int m,n;
bool visited[1001];
vector<int> adj[1001];
//10 8
//1 2
//2 3 
//2 4
//3 6 
//3 7 
//6 7 
//5 8 
//8 9


// init
void inp(){
	cin >> m >> n;
	for(int i=0; i<n;i++){
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	memset(visited,false,sizeof(visited));
}


void dfs(int x){
	visited[x] = true;
	for(auto a : adj[x]){
		if(!visited[a]){
			dfs(a);
		}
	}
}

void bfs(int z){
	queue<int> q;
	q.push(z);
	visited[z] = true;
	while(!q.empty()){
		int v = q.front(); // get the first element
		visited[v] = true; // 
		q.pop(); //delete the first element
		for(int i : adj[v]){
			if(!visited[i]){
				q.push(i);
				visited[i]  =true;
			}
		}
	}
}
//check conected component
int conectedcomponent(){
	int count = 0;
	for(int i=1; i <= m; i++){
		if(!visited[i]){
			count ++;
			bfs(i);
		}
	}
	return count;
}

int main(){
	inp();
	if(conectedcomponent() == 1){
		cout <<" is conected component\n";
	}
	else cout << " not conected componet";
	return 0;
}