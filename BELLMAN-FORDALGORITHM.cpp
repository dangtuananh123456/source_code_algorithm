#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e7;


//tìm đường đi ngắn nhất từ đỉnh x tới tất cả các đỉnh còn lại

int main(){
	int m, n;
	vector<tuple<int,int,int>> v;
	cin >> m >> n;
	for(int i = 1; i <= n; i++){
		int x, y, w;
		cin >> x >> y >> w;
		v.push_back({x,y,w});
	}
	int x; cin >> x;
	int distance[m+1];
	for(int i = 1; i <= m; i++) distance[i] = maxn;
	distance[x] = 0;
	for(int i = 1; i <= m; i++){
		for(auto it : v){
			int x, y, z;
			tie(x, y, z) = it;
			distance[y] = min(distance[y], distance[x] + z);
		}
	}
	for(int i = 1; i <= m; i++){
		cout << distance[i] << " ";
	}
	return 0;
}
//4 5
//1 2 3
//1 3 5
//2 3 2
//2 4 1
//3 4 7
//14 5
//1 2 3
//1 3 5
//2 3 2
//2 4 1
//3 4 7
//1
