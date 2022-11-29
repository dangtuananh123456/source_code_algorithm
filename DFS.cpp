#include<bits/stdc++.h>
using namespace std;
int m,n;
vector<int> adj[1001];
bool visited[1001];
int color[1001];

//input 
//9 11
//1 2
//1 3
//1 5
//2 4
//3 6
//3 7 
//3 9 
//5 8
//8 9
//7 9
//1 9
void inp(){
	cin >> m >> n;
	for(int i=0; i < n; i++){
		int x,y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	memset(visited, false, sizeof(visited));
	memset(color, 0, sizeof(color));
}

void DFS(int x){
	cout << x << endl;
	visited[x]=true;
	for(auto a : adj[x]){
		if(!visited[a]){
			DFS(a);
		}
	}
}

//kiem tra chu trinh tren do thi vo huong
bool DFS_1(int x, int u){
	visited[x] = true;
	for(auto it : adj[x]){
		if(!visited[it]){
			if(DFS_1(it, x)) return true;
		}
		else{
			if(it != u) return true;
		}
	}
	return false;
}

//kiem tra chu trinh tren do thi co huong
bool DFS_2(int u){
	color[u] = 1;//danh dau dang duoc duyet
	for(auto it : adj[u]){
		if(color[it] == 0){
			if(DFS_2(it)) return true;
		}
		else if(color[it] == 1) return true;
	}
	color[u] = 2;//da duoc duyet xong
	return false;
}
int main(){
	inp();
	if(DFS_1(1 , 0)) cout << "yes";
	else cout << "no";
}