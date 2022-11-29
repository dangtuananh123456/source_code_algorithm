#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
#include<queue>
using namespace std;
int m, n;
vector<int> adj[1001];
vector<int> topo;
int radius[1001];
bool visited[1001];

void input(){
	memset(radius, 0, sizeof(radius));
	cin >> m >> n; // nhap so luong dinh va so luong canh cua do thi
	for(int i = 1; i <= n; i++){
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		radius[y]++;
	}
	memset(visited, false, sizeof(visited));
}

void topologicalalgorithm_kahn(){
	queue<int> q;
	for(int i = 1; i <= m; i++){
		if(radius[i] == 0) q.push(i);
	}
	while(!q.empty()){
		int tem = q.front();
		topo.push_back(tem);
		q.pop();
		for(auto it : adj[tem]){
			radius[it]--;
			if(radius[it] == 0){
				q.push(it);
			}
		}
	}
	for(auto it : topo){
		cout << it << " ";
	}
}

void topological(int x, int pa){
	visited[x] = true;
	for(auto it : adj[x]){
		if(!visited[it]){
			topological(it, x);
		}
	}
	topo.push_back(x);
}

int main(){
	input();
	topologicalalgorithm_kahn();
	return 0;
}
//7 6
//1 2 
//2 3
//2 4
//4 5
//1 6
//6 7

 