#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct egde{
	int u,v;
	int w;
};

int m,n;
vector<pair<int,int>> adj[1001];
vector<egde> mst;
bool used[1001];
int parent[1001];
int d[1001];


void input(){
	cin >> n >> m;
	for(int i = 1; i <= m; i ++){
		int x,y,z;
		cin >> x >> y >> z;
		adj[x].push_back({y,z});
		adj[y].push_back({x,z});
	}
	memset(used, false, sizeof(used));
	for(int i = 1; i<= n; i++) d[i] = INT_MAX;
}

void Prim(int a){
	//used[a] = true;//đánh dấu là a đã được sử dụng
//	while(result.size() < n - 1){
//		int min = INT_MAX;
//		int X,Y;
//		for(int i = 1; i <= n; i++){
//			if(used[i]){//dinh i thuoc vao tap Mmst
//				for(pair<int,int> it : mst[i]){
//					if(!used[it.first] && it.second < min){// dinh it.first chua duoc them vao cay khung va canh giu hai dinh i va it.first co trong so nho hon min
//						min = it.second;
//						X = i; Y = it.first;
//					}
//				}
//			}
//		}
//		d+= min;
//		result.push_back({X,Y,min});
//		used[Y] = true; //danh dau la dinh Y da duoc them vao khung
//	}
	//tạo hàng đợi ưu tiên
	priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> Q;
	Q.push({0,a});
	int res = 0;
	while(!Q.empty()){
		pair<int,int> p = Q.top();
		Q.pop();
		int dinh = p.second, trongso = p.first;
		if(used[dinh]) continue;
		res += trongso;
		used[dinh] = true;
		if(a != dinh){
			mst.push_back({dinh,parent[dinh],trongso});
		}
		for(auto i : adj[dinh]){
			int x = i.first, y = i.second;
			if(!used[x] && d[x] > y){
				parent[x] = dinh;
				Q.push({y,x});
				d[x] = y;
			}
		}
	}
	cout << "chieu dai cuc tieu cua cay: " << res;
	cout << endl;
	for(egde it : mst){
		cout << it.u << " " << it.v << " " << it.w << endl;
	}
}
int main(){
	input();
	Prim(1);
	return 0;
}
//6 9
//1 2 9
//1 3 4
//2 3 1 
//2 4 6
//3 4 7
//3 5 2
//4 5 3
//4 6 10
//5 6 8
//1