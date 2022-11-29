#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;

//tìm đường đi ngắn nhất từ mọi đỉnh của đồ thị đến những đỉnh còn lại;

int main(){
	int n, m; 
	cin >> n >> m;
	int adj[n+1][n+1];
	memset(adj, 0, sizeof(adj));
	for(int i = 1; i <= m; i++){
		int x, y, z;
		cin >> x >> y >> z;
		adj[x][y] = z;
		adj[y][x] = z;
	}
	int distance[n+1][n+1];
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(i == j) distance[i][i] = 0;
			else if(adj[i][j]) distance[i][j] = adj[i][j];
			else distance[i][j] = 100000;
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			for(int k = 1; k <= n; k++){
				distance[j][k] = min(distance[j][k], distance[j][i] + distance[i][k]); 
			}
		}
	}
	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= n; j++){
			cout << distance[i][j] << "  ";
		}
		cout << endl;
	}
	return 0;
}
//4 5
//1 2 3
//1 3 5
//2 3 2
//2 4 1
//3 4 7