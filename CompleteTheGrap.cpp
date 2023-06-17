#include<iostream>
#include<queue>
#include<vector>
#include<tuple>

using namespace std;

#define Max 1e6 + 1
int m, n, source, destination, target;
vector<pair<int, int>> adj[101];
vector<tuple<int, int, int>> edges;
int distanceMin[101];
bool visited[101];
void input() {	
	cin >> m >> n >> target >> source >> destination;
	for (int i = 0; i < n; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		adj[x].push_back({ y, z });
		adj[y].push_back({ x, z });
		edges.push_back({ x, y, z });
	}
	memset(visited, false, sizeof(visited));
	memset(distanceMin, Max, sizeof(distanceMin));
	distanceMin[source] = 0;
}

void disjitra2() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	distanceMin[source] = 0;
	q.push({ 0, source });
	int Trace[101];
	memset(Trace, 0, sizeof(Trace));
	Trace[source] = -1;
	while (!q.empty()) {
		int DisMin, vertex;
		tie(DisMin, vertex) = q.top(); q.pop();

		//cout << "[" << DisMin << " ; " << vertex << "]" << endl;
		if (DisMin > distanceMin[vertex]) continue;
		for (auto it : adj[vertex]) {
			int a, b;
			tie(a, b) = it;
			bool check = false;
			if (b == -1) {
				b = 1;
				check = true;
			}
			if (distanceMin[a] > distanceMin[vertex] + b) {
				//update min distance value
				distanceMin[a] = distanceMin[vertex] + b;
				q.push({ distanceMin[a], a });
				visited[a] = check;
				Trace[a] = vertex;
			}
		}
	}
	int valueCheck = 2;

	//dk nay full -1 + set value target - distanceMin[destination]
	if (distanceMin[destination] < target && visited[destination] == true) {
		valueCheck = 0;
	}
	//dieu kien nay chi can fill -1 by 1 la ok
	else if (distanceMin[destination] == target) {
		valueCheck = 1;
	}
	else valueCheck = 2;

	if (valueCheck == 0) {
		int index = destination;
		while (Trace[index] != -1 || index != source) {
			bool check = false;
			/*for (int i = 0; i < adj[index].size(); i++) {
				if (adj[index][i].first == Trace[index] && adj[index][i].second == -1) {
					adj[index][i].second = 1 + target - distanceMin[destination];
					check = true;
					break;
				}
			}*/
			for (int i = 0; i < edges.size(); i++) {
				int x, y, z;
				tie(x, y, z) = edges[i];
				if ((x == index && y == Trace[index] && z == -1)
					|| (x == Trace[index] && y == index && z == -1)) {
					check = true;
					z = 1 + target - distanceMin[destination];
					edges[i] = { x, y, z };
					break;
				}
			}
			if (check) break;
			//cout << index << ";" << Trace[index] << endl;
			index = Trace[index];
		}
	}

	if (valueCheck != 2) {
		cout << "[";
		for (auto it : edges) {
			int x, y, z;
			tie(x, y, z) = it;
			if (z == -1) z = 1;
			cout << "[" << x << "," << y << "," << z << "] ";
		}
		cout << "]";
	}
	else {
		cout << "[]" << endl;
	}
	
}


int main() {
	input();
	disjitra2();
}

//5 6 1
//1 2 3
//1 3 5
//2 3 2
//2 4 4
//3 4 2
//4 5 1

//n = 5, edges = [[4, 1, -1], [2, 0, -1], [0, 3, -1], [4, 3, -1]]
//, source = 0, destination = 1, target = 5

//5 4 1 2 5
//5 2 -1
//3 1 -1
//1 4 -1
//5 4 -1
 

// n = 3, edges = [[0,1,-1],[0,2,5]], source = 0, destination = 2, target = 6
//3 2 1 3 6
//1 2 -1
//1 3 5

//n = 4, edges = [[1, 0, 4], [1, 2, 3], [2, 3, 5], [0, 3, -1]],
//source = 0, destination = 2, target = 6
//4 4 1 3 6
//2 1 4
//2 3 3 
//3 4 5
//1 4 -1