#include<iostream>
using namespace std;
int M, N;
bool adj[1001][1001];// bieu thi ton tai canh noi giua hai dinh
bool check[1001];// danh dau cac dinh da duoc tham
int result[1001];//in ket qua

void input(){
	cin >> M >> N;
	memset(adj, false, sizeof(adj));
	for(int i = 1; i <= N; i++){
		int a, b;
		cin >> a >> b;
		adj[a][b] = true;
		adj[b][a] = true;
	}
	memset(check, false, sizeof(check));
}

void print_result(){
	for(int i = 1; i <= M; i++){
		cout << result[i] << " ";
	}
	cout << result[1] << endl;
}

void Hamlinton(int u){
	//xet tat ca cac truong hop xay ra
	for(int v = 1; v <= M; v++){
		if(!check[v] && adj[result[u - 1]][v]){//neu ton tai canh 
			result[u] = v;
			if(u < M){//neu chu trinh chua hoan thien thi ta tiep tuc goi recursion den cac truong hop tiep theo
				check[v] = true;//danh dau
				Hamlinton(u + 1);// goi de quy den cau hinh tiep theo
				check[v] = false;// backtracking trong recursion
			}
			else{
				if(adj[v][result[1]]){
					print_result();
				}
			}
		}
	}
}

int main(){
	input();
	result[1] = 1;
	check[1] = true;
	Hamlinton(2);
	return 0;
}
//5 6
//1 2
//1 3
//2 4
//3 5
//4 1
//5 2
