#include<iostream>
#include<vector>

using namespace std;

int visited[20000] = { 0, };

bool isBipartiteGraph(vector<vector<int>>& adj, int s, int color);

int main() {
	int k, node, edge;
	int input1, input2;
	bool flag;
	cin >> k;
	for (int j = 0; j < k; j++) {
		flag = true;
		cin >> node >> edge;
		vector<vector<int>> adj(node + 1, vector <int>(0));

		for (int i = 0; i < edge; i++) {
			cin >> input1 >> input2;
			adj[input1].push_back(input2);
			adj[input2].push_back(input1);
		}

		for (int i = 1; i <= node; i++) {
			if (visited[i] == 0) {
				if (!isBipartiteGraph(adj, i, 1)) {
					cout << "NO" << "\n";
					flag = false;
					break;
				}
			}
		}
		if (flag) cout << "YES" << "\n";
		for (int i = 0; i < node + 1; i++) visited[i] = 0;
	}
}
bool isBipartiteGraph(vector<vector<int>>& adj, int s, int color) {
	if (visited[s] == color)
		return false;
	else if (visited[s] != 0)
		return true;

	color = color == 1 ? 2 : 1;
	visited[s] = color;

	for (auto u : adj[s]) {
		if (!isBipartiteGraph(adj, u, color)) return false;
	}
	return true;
}