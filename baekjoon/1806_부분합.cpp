#include<iostream>
#include<vector>

using namespace std;

int main() {
	int N, S, input, result = 987654321;
	long long sum = 0;
	vector<int> v;
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> input;
		v.push_back(input);
	}
	int start = 0, end = 0;
	for (end = 0; end < N; end++) {
		sum += v[end];
		for (start; sum >= S; start++) {
			result = min(result, end - start + 1);
			sum -= v[start];
		}
	}
	if (result == 987654321) result = 0;
	cout << result << "\n";
}