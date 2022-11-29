#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//10 11
//1 2 
//1 3
//1 5
//1 10
//2 4
//3 6 
//3 7
//3 9
//6 7
//5 8
//8 9

int m,n;
vector<int> adj[1001];
bool visited[1001];
void inp(){
	cin >> m >> n;
	for(int i=0; i < n; i++){
		int x,y;
		cin >> x >> y;
		adj[y].push_back(x);
		adj[x].push_back(y);
	}
	memset(visited, false, sizeof(visited));
}
void BFS(int x){
	queue<int> p;
	p.push(x);
	visited[x] = true;
	while(!p.empty()){
		int v = p.front();//get the first top
		p.pop(); // erase the first top
		cout << v << "  ";
		for(auto a : adj[v]){
			if(!visited[a]){
				p.push(a);
				visited[a] = true;
			}
		}
	}
}

int main(){
	inp();
	BFS(1);
	return 0;
}