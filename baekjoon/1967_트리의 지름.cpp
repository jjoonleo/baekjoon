#include <iostream>
#include <vector>
#include <utility>

using namespace std;

vector<vector<pair<int, int>>> tree(1000000);
bool visited[1000000][2] = { 0, };

pair<int, int> dfs(int x, int index) {
	pair<int, int> result = make_pair(x, 0);
	visited[x][index] = 1;
	for (auto i : tree[x]) {
		if (!visited[i.first][index]) {
			pair<int, int> tmp = dfs(i.first, index);
			if (result.second < tmp.second + i.second) {
				result.first = tmp.first;
				result.second = tmp.second + i.second;
			}
		}
	}
	return result;
}

int main() {
	int numberOfNode;
	cin >> numberOfNode;
	for (int j = 1; j < numberOfNode; j++) {
		int in1, in2, in3;
		cin >> in1 >> in2 >> in3;
		tree[in1].push_back(make_pair(in2, in3));
		tree[in2].push_back(make_pair(in1, in3));
	}
	int result = dfs(1, 1).first;
	result = dfs(result, 2).second;
	cout << result;
}