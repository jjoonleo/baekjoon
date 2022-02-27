#include<iostream>
#include<vector>
#include<tuple>

#define INF 987654321

using namespace std;

int main() {
	int tc;
	int node, road, worm;
	int distance[501];
	vector<tuple<int, int, int>> edges;
	cin >> tc;
	for (int i = 0; i < tc; i++) {
		edges.clear();
		cin >> node >> road >> worm;
		for (int j = 0; j < road; j++) {
			int a, b, w;
			cin >> a >> b >> w;
			edges.push_back(tie(a, b, w));
			edges.push_back(tie(b, a, w));
		}
		for (int j = 0; j < worm; j++) {
			int a, b, w;
			cin >> a >> b >> w;
			w *= -1;
			edges.push_back(tie(a, b, w));
		}

		distance[1] = 0;
		for (int j = 1; j <= node-1; j++) {
			
			for (auto e : edges) {
				int a, b, w;
				tie(a, b, w) = e;
				distance[b] = min(distance[b], distance[a] + w);
			}
		}

		int yes = false;
		for (auto e : edges) {
			int a, b, w;
			tie(a, b, w) = e;
			if (distance[b] > distance[a] + w) {
				cout << "YES\n";
				yes = true;
				break;
			}
		}
		if (!yes) {
			cout << "NO\n";
		}
		for (int j = 1; j < node; j++) {
			distance[j] = INF;
		}
	}
}