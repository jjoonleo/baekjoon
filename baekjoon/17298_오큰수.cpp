#include<stack>
#include<vector>
#include<iostream>
#include<utility>

using namespace std;

int main() {
	int n, input;
	int* result = new int[1000000];
	stack<pair<int, int>> s;
	cin >> n;
	cin >> input;
	s.push(make_pair(input, 1));
	for (int i = 2; i <= n; i++) {
		cin >> input;
		while (!s.empty() && s.top().first < input) {
			result[s.top().second] = input;
			s.pop();
		}

		s.push(make_pair(input, i));
	}
	for (int i = 1; i <= n; i++) {
		if (result[i])
			cout << result[i] << " ";
		else
			cout << "-1 ";
	}
}