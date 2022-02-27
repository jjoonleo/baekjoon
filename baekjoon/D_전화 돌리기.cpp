#include <iostream>
#include <vector>
#include <utility>

using namespace std;

vector<vector<int>> tree(1000000);
bool visited[1000000] = { 0, };
int memoi[1000000] = { 0, };

bool dfs(int x) {
	if (visited[x]) 
		return false;
	visited[x] = 1;
	bool result = true;
	for (auto i : tree[x]) {
		bool dfsm;
		if (memoi[i] == -1) {
			dfsm = dfs(i);
			memoi[i] = dfsm;
		}
		result &= memoi[i];
	}
	return result;
}

int main() {
	int node, edge;
	cin >> node >> edge;
	for (int i = 0; i < edge; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		tree[n1].push_back(n2);
	}
	for (int j = 0; j < node; j++) {
		memoi[j] = -1;
	}
	int result = 0;
	for (int i = 1; i < node; i++) {
		if (memoi[i] == -1) {
			if (dfs(i)) 
				result++;
			for (int j = 0; j < node; j++) {
			visited[j] = 0;
		}
		}
		else {
			if (memoi[i]) 
				result++;
		}
		
	}
	cout << result;

}