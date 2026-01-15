#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>  // 추가: sort 함수 사용
using namespace std;

struct Vertex {
	int id;
	vector<int> adj; // adjacent vertices
};

void BFS(const vector<Vertex>& graph, int R) {
	vector<bool> visited(graph.size(), false);
	queue<int> q;
	vector<int> visitOrder(graph.size(), 0);
	int visitCount = 1;

	q.push(R);
	visited[R] = true;
	visitOrder[R] = visitCount++;

	while (!q.empty()) {
		int currentId = q.front();
		q.pop();

		for (int i = 0; i < graph[currentId].adj.size(); i++) {
			if (!visited[graph[currentId].adj[i]]) {
				visited[graph[currentId].adj[i]] = true;
				q.push(graph[currentId].adj[i]);
				visitOrder[graph[currentId].adj[i]] = visitCount++;
			}
		}
	}

	for (int i = 0; i < visitOrder.size(); i++) {
		if (visitOrder[i] == 0) cout << 0 << "\n";
		else cout << visitOrder[i] << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, R;
	cin >> N >> M >> R;
	R--;

	vector<Vertex> graph(N);
	for (int i = 0; i < N; i++) {
		graph[i].id = i;
	}

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		graph[a].adj.push_back(b);
		graph[b].adj.push_back(a);
	}

	for (int i = 0; i < N; i++) {
		sort(graph[i].adj.begin(), graph[i].adj.end());
	}

	BFS(graph, R);

	return 0;
}
