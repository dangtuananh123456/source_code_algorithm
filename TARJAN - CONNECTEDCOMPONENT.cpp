#include<iostream>
#include<stack>
#include<string.h>
using namespace std;
int M, N;
int number[1001];// danh dau thu tu duyet
int low[1001]; //danh dau de xet chot
bool adj[1001][1001];
bool check[1001]; // xem con ton tai trong danh sach(cay)
int count = 0, componentcount = 0;
stack<int> vertex;

void input(){
	cin >> N >> M;
	memset(adj, false, sizeof(adj));
	for(int i = 1; i <= M; i++){
		int a, b;
		cin >> a >> b;
		adj[a][b] = true;
	}
	memset(number, 0, sizeof(number));
	memset(low, 0, sizeof(low));
	memset(check, true, sizeof(check));
}

void Tarjan(int u){
	vertex.push(u);
	count++;
	number[u] = count;
	low[u] = number[u];
	for(int i = 1; i <= N; i++){
		if(adj[u][i] && check[i]){
			if(number[i] != 0){
				low[u] = min(low[u], low[i]);
			}
			else{
				Tarjan(i);
				low[u] = min(low[u], low[i]);
			}
		}
	}
	if(low[u] == number[u]){
		componentcount ++;
		cout << "component " << componentcount << " : ";
		int v = 0;
		while(v != u){
			v = vertex.top();
			vertex.pop();
			cout << v << " ";
			check[v] = false;
		}
		cout << endl;
	}
}

int main(){
	input();
	for(int i = 1; i <= N; i++){
		if(number[i] == 0){
			Tarjan(i);
		}
	}
	for(int i = 1; i <= N; i++){
		cout << number[i] << "  " << low[i] << endl;
	}
}

//11 15
//1 2
//1 8 
//2 3
//3 4
//4 2
//4 5
//5 6
//6 7
//7 5
//8 9 
//9 4
//9 10
//10 8
//10 11
//11 8