#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	vector<int> v;
	vector<int> check;
	vector<int> result;
	cin >> n;
	int input, pre;
	cin >> input;
	check.push_back(1);
	v.push_back(input);
	pre = input;
	for (int i = 1; i < n; i++) {
		
		cin >> input;
		if (pre == input) {
			check.back()++;
		}
		else {
v.push_back(input);
		check.push_back(1);
		}
		pre = input;
	}
	int index = -1;

	for (int i = 0; i < n; i+=check[index]) {
		index++;
		for (int j = 0; j < check[index]; j++) {
			if (i + check[index] + 1 > n) cout << "-1 ";
			else cout << i + check[index] + 1 << " ";
		}
	}

}