#include<iostream>
using namespace std;
int N, M;
bool adj[1001][1001];
void input(){
	memset(adj, false, sizeof(adj));
	cin >> N >> M;
	for(int i = 1; i <= N; i++){
		adj[i][i] = true;//duong di den chinh no thi luon ton tai
	}
	for(int i = 1; i <= M; i++){
		int a, b;
		cin >> a >> b;
		adj[a][b] = true;
		adj[b][a] = true;
	}
}

//thuat toan warshall
void solve(){
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			for(int k = 1; k <= N; k++){
				adj[j][k] = adj[j][k] || (adj[j][i] && adj[i][k]);
			}
		}
	}
	int count = 0;
	bool check[N + 1];
	memset(check, false, sizeof(check));
	for(int i = 1; i <= N; i++){
		if(!check[i]){
			cout << endl;
			cout << "connected component " << ++count << " : ";
		}
		for(int j = 1; j <= N; j++){
			if(adj[i][j] && !check[j]){
				cout << j << " ";
				check[j] = true;
			}
		}
	}
}

int main(){
	input();
	solve();
	return 0;
}

//12 9
//1 4
//1 3
//2 4
//1 5
//6 7
//6 8
//9 10
//9 11
//11 12

