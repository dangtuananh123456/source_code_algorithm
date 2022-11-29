#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int m,n,xa,ya,xb,yb;
char c[1001][1001];
bool visited[1001][1001];
int x[4]={-1,0,1,0};
int y[4]={0,-1,0,1};

void dfs(int i, int j){
	cout << i <<" "<< j << endl;
	visited[i][j] = true;
	for(int k = 0; k<4 ; k++){
		int i1 = i + x[k];
		int j1 = j + y[k];
		if(i1 >= 1 && i1 <=m && j1 <= m && j1 >= 1 && !visited[i1][j1] && c[i1][j1] == 'x'){
			dfs(i1,j1);
		}
	}
}

void bfs(int i, int j){
	cout << i <<"  "<<j << endl;
	queue<pair<int, int >> q;
	q.push({i,j});
	c[i][j] = 'o';
	while(!q.empty()){
		pair<int, int> top = q.front();
		q.pop();
		for(int k= 0; k<4;k++){
			int i1 =  top.first + x[k];
			int j1 = top.second + y[k];
			if(i1 <= m && i1 >=1 && j1 >=1 && j1 <=m && c[i1][j1]=='x'){
				q.push({i1,j1});
				cout << i1 <<" "<< j1 << endl;
				c[i1][j1] = 'o';
			}
		}
	}
}

void path(){
	int count =0 ;
	for(int i=1; i<=m;i++){
		for(int j=1; j<=m;j++){
			if(c[i][j] == 'x' ){
				cout<<"thanh phan lien thong thu "<< count+1 << " :"<<endl;
				bfs(i,j);
				++count; 
			}
		}
	}
}
void inp(){
	cin >> m;
	for(int i=1; i<=m;i++){
		for(int j=1;j<=m;j++){
			cin >> c[i][j];
		}
	}
	memset(visited,false,sizeof(visited));
}
int main()
{
	inp();
	path();
	return 0;
}

//6 
//x x x o o o
//o o x o o o
//o x x x x o
//o o o o o x
//x x o x o x
//x o x x o x