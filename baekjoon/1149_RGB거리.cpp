#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector<vector<int>> costs;
int memoization[3][1000] = { 0, };

int minCost(int curHouse, int preColor) {
	int result = 0;
	if (curHouse == costs.size()) return 0;
	if (memoization[preColor][curHouse]) return memoization[preColor][curHouse];
	result += min(costs[curHouse][(preColor + 1) % 3]+minCost(curHouse+1, (preColor+1)%3),
		costs[curHouse][(preColor + 2) % 3] + minCost(curHouse + 1, (preColor + 2) % 3));
	memoization[preColor][curHouse] = result;
	return result;
}

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		vector<int> tmp;
		for (int j = 0; j < 3; j++) {
			int input;
			cin >> input;
			tmp.push_back(input);
		}
		costs.push_back(tmp);
		tmp.clear();
	}
	cout << min(minCost(0, 0),min(
		minCost(0, 1),
		minCost(0, 2)));
}