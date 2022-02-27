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
	for (int i = 0; i < numberOfNode; i++) {
		vector<pair<int, int>> tmp;
		int nodeIndex;
		cin >> nodeIndex;
		int input = 0, input2;
		while (true) {
			cin >> input;
			if (input == -1) break;
			cin >> input2;
			tmp.push_back(make_pair(input, input2));
		}
		tree[nodeIndex] = tmp;
		tmp.clear();
	}
	int result = dfs(1, 1).first;
	result = dfs(result, 2).second;
	cout << result;
}