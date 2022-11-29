#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<unordered_map>
using namespace std;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};
char c[1001][1001];
int x,y,m,n,u,v;

struct P{
	int tem1 , tem2;
} a[10][10];

void inp(){
	cin >> m >> n;
	for(int i = 1; i<=m ; i++){
		for(int j = 1; j <= n ; j++){
			cin >> c[i][j];
		}
	}
}
//get point of A
void getpoint(){
	for(int i=1; i<= m;i++){
		for(int j=1; j<=n;j++){
			if(c[i][j] == 'A'){
				x = i;
				y = j;
				return;
			}
		}
	}
}
//
////search the road by dfs
//bool dfs_1(int x, int y){
//	if(c[x][y] == 'B') return true;
//	c[x][y] = 'o';
//	for(int k = 0; k<4; k++){
//		int i = x + dx[k];
//		int j = y +dy[y];
//		if(i <= m && i>=1 && j <= n && j>=1 && c[i][j] != 'o'){
//			if(dfs_1(i,j)) return true;
//		}
//	}
//	return false;
//}
//
//// rearch the road by bfs
//bool bfs_1(int x, int y){
//	if(c[x][y] == 'B') return true;
//	queue<pair<int, int >> q;
//	q.push({x,y});
//	c[x][y] = 'o';
//	while(!q.empty()){
//		pair<int,int> p = q.front();
//		q.pop();
//		for(int k =0; k<4 ; k++){
//			int x1 = p.first + dx[k];
//			int y1 = p.second + dy[k];
//			if(x1 <= m && x1 >=1 && y1 <=n && y1>=1 &&c[x1][y1] != 'x'){
//				if(c[x1][y1] == 'B') return true;
//				q.push({x1,y1});
//				c[x1][y1] = 'o';
//			}
//		}
//	}
//	return false;
//}
//
////shortest road on grid graph
//bool bfs_2(int x, int y){
//	if(c[x][y] == 'B') return true;
//	c[x][y] = 'o';
//	queue<pair<int,int>> q;
//	q.push({x,y});
//	while(!q.empty()){
//		pair<int,int> p = q.front();
//		q.pop();
//		for(int k= 0; k<4;k++){
//			int i = p.first + dx[k];
//			int j = p.second + dy[k];
//			if( i <=m && i >=1 && j <= n && j >=1 && c[i][j] != 'o'){
//				a[i][j] = a[p.first][p.second] + 1;
//				if(c[i][j] == 'B') {
//					u = i;
//					v = j;
//					return true;
//				}
//				q.push({i,j});
//				c[i][j] = 'o';
//			}
//		}
//	}
//	return false;
//}

bool bfs_3(){
	if(c[x][y] == 'B') return true;
	queue<pair<int,int>> q;
	q.push({x,y});
	c[x][y] = 'o';
	while(!q.empty()){
		pair<int,int> p = q.front();
		q.pop();
		for(int i = 0; i < 4; i++){
			int x1 = p.first + dx[i];
			int y1 = p.second + dy[i];
			if(x1 <= m && x1 >=1 && y1 <=n && y1 >=1 && c[x1][y1] != 'o'){
				if(c[x1][y1] == 'B') {
					u = x1;
					v = y1;
					return true;
				}				
				a[x1][y1].tem1 = p.first;
				a[x1][y1].tem2 = p.second;
				c[x1][y1] = 'o';
				q.push({x1,y1});
			}
		}
	}
	return false;
}

//path
void path(){
	while( u != x && v != y){
		cout << u << " "<< v << endl;
		int i = a[u][v].tem1;
		int j = a[u][v].tem2;
		u = i;
		v = j;
	}
	cout << u << " " << v;
}

int main(){
	inp();
	getpoint();
	if(bfs_3()) {
		path();
	}
	else cout << "no way\n";
	return 0;
}

//4 6
//A o o o x x
//x x o o x o
//x x o o o o
//o x B o x x 










