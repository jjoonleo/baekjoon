#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main() {
	string t, s;
	cin >> s >> t;
	int cnt = 0;
	vector<int> visited(s.size(), 0);
	vector<int> startPoint(t.size(), 0);
	int j = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == t[j] && !visited[i]) {
			startPoint[j] = i;
			visited[i] = true;
			if (j >= t.size() - 1) {
				cnt++;
				j = 0;
				i = startPoint[0];
				continue;
			}
			i = max(startPoint[j + 1], i);
			j++;
		}
	}
	cout << cnt << "\n";
}