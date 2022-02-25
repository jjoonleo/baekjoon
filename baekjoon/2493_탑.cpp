#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	vector<int> v;
	scanf("%d", &n);
	int tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}
	vector<int> result(v.size());
	//for(auto i: v){printf("%d ",i);}

	for (int i = 0; i < v.size(); i++) {
		if (i - 1 < 0) {
			result[i] = -1;
			continue;
		}
		if (v[i] < v[i - 1]) {
			result[i] = i - 1;
		}
		else {
			int j = i - 1;
			while (true) {
				if (result[j] == -1) {
					result[i] = -1;
					break;
				}
				if (v[result[j]] > v[i]) {
					result[i] = result[j];
					break;
				}
				j = result[j];
			}
		}
	}
	for (auto i : result) { printf("%d ", i + 1); }
}
