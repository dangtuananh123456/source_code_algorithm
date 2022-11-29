#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#define maxn 100000
using namespace std;
int m,n;
vector<pair<int,int>> adj[1001];
bool check[1001];
int distance_min[1001];

void input(){
	cin >> m >> n;
	for(int i = 1; i <= n; i++){
		int x, y, z;
		cin >> x >> y >> z;
		adj[x].push_back({y, z});
	}
}

void disjktra(){
	for(int i = 2; i <= m; i++){
		distance_min[i] = maxn;
	}
	distance_min[1] = 0;
	int des_vertex = 5;
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
	q.push({0 , 1});
	while(!q.empty()){
		pair<int,int> x = q.top();
		q.pop();
		int min_dis, node;
		tie(min_dis, node) = x;
		if(min_dis > distance_min[node]) continue;
		for(auto it : adj[node]){
			int a, b;
			tie(a, b) = it;
			if(distance_min[a] > b + min_dis){
				distance_min[a] = b + min_dis;
				q.push({distance_min[a], a});
			}
		}
	}
//	for(int i = 1; i <= 5; i++){
//		cout << distance_min[i] << " ";
//	}
}
//number min path from vertex a to vertex b
void solve(){
	int number_min_path[m + 1];
	for(int i = 1; i <= m; i++){
		number_min_path[i] = 0;
	}
	number_min_path[1] = 1;
	for(int i = 1; i <= m; i++){
		if(!check[i]){
			for(auto it : adj[i]){
				int x, y;
				tie(x, y) = it;
				if(distance_min[x] == distance_min[i] + y){
					number_min_path[x] += number_min_path[i];
				}
			}
			check[i] = true;
		}
	}
	for(int i = 1; i <= m; i++){
		cout << i << " " << number_min_path[i] << endl;
	}
}

int main(){
	input();
	disjktra();
	solve();
}
//5 6 
//1 2 3
//1 3 5
//2 3 2
//2 4 4
//3 4 2
//4 5 1
