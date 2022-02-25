#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<utility>

using namespace std;
vector<int> v;
stack<long long> s;

int main() {
	long long n, input, largest = 0, check;
	s.push(0);
	v.push_back(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> input;
		v.push_back(input);

		while (v[s.top()] > input) {
			check = v[s.top()];
			s.pop();
			largest = max(largest, check * (i - s.top() - 1));
		}
		s.push(i);
	}
	while (s.size() > 1) {
		int check = v[s.top()];
		s.pop();
		largest = max(largest, check * (n - s.top()));
	}
	cout << largest << endl;


}
