#include <iostream>
#include <utility>
#include <vector>
#include <queue>

#define INF 987654321

using namespace std;

bool visited[1001] = { 0, };

void dijkstra(int x, int n, vector<vector<pair<int, int>>> graph, vector<int>& distances) {
	priority_queue<pair<int, int>> q;

	for (int i = 1; i < n+1; i++) {
		distances[i] = INF;
		visited[i] = false;
	}

	distances[x] = 0;
	q.push({ 0, x });
	while (!q.empty()){
		int a = q.top().second; q.pop();
		if (visited[a]) continue;
		visited[a] = true;
		for (auto u : graph[a]) {
			int b = u.first, w = u.second;
			if (distances[b] > distances[a] + w) {
				distances[b] = distances[a] + w;
				q.push({ -distances[b],b });
			}
		}
	}
	
}

int main() {
	int node, road, start;
	cin >> node >> road >> start;
	vector<vector<pair<int,int>>> graph(node+1);
	vector<int> distances1(node+1), distances2(node+1);

	for (int i = 0; i < road; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		graph[a].push_back({b, w});
	}

	dijkstra(start, node, graph, distances1);
	

	for (int i = 1; i <= node; i++) {
		if (i != start) {
			dijkstra(i, node, graph, distances2);
			
			distances1[i] += distances2[start];
		}
	}

	int result = 0;
	for (auto d: distances1){
		if(d != 987654321)
			result = max(result, d);
	}
	cout << result << "\n";
}