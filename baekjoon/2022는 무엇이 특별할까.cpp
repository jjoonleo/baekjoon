#include<iostream>
#include<stack>
#include<vector>
#include<cmath>

using namespace std;

int main() {
	int N, d;
	bool isUsed[10] = { 0, };
	stack<int> s;
	vector<int> v;

	cin >> N >> d;
	for (int i = N; i > 0; i/=d) {
		s.push(i % d);
	}
	for (int i = 0; s.size(); i++) {
		v.push_back(s.top());
		cout << s.top();
		s.pop();
	}


	if (v.size() != d) {
		cout << "-1";
		return 0;
	}


	for (auto i : v) {
		cout << i;
	}cout << endl;
	int result = 0;
	for (int i = 0; i < v.size(); i++) {
		result += v[i] * pow(d, v.size() - i - 1);
	}
	cout << result;
}