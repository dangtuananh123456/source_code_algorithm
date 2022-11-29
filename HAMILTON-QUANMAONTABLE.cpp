#include<iostream>
#include<math.h>
using namespace std;

int M;
int result[1001][1001];
bool visited[1001][1001];

void input(){
	cin >> M;
	memset(visited, false, sizeof(visited));
}

void printresult(){
	for(int i = 1; i <= M; i++){
		for(int j = 1; j <= M; j++){
			cout << result[i][j] << "  ";
		}
		cout << endl;
	}
	cout << endl;
}
void solve(int x, int y){
	for(int i = x - 2; i <= x + 2; i++ ){
		if(i < 1 || i > M) continue;
		for(int j = y - 2; j <= y + 2; j++){
			if(j < 1 || j > M) continue;
			int tem = abs(x - i) * abs(y - j);
			if(tem == 2 && !visited[i][j]){
				result[i][j] = result[x][y] + 1;
				if(result[i][j] < M*M){
					//danh dau o da duoc tham
					visited[i][j] = true;
					//goi den cau hinh tiep theo
					solve(i, j);
					//backtracking
					visited[i][j] = false;
				}
				else{
					printresult();
					exit(0);
				}
			}
		}
	}
}

int main(){
	int x, y;
	cin >> x >> y;
	input();
	visited[x][y] = true;
	result[x][y] = 1;
	solve(x, y);
} 
// 3 3 8