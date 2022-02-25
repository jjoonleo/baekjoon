#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main() {
	int numberOfPeople, numberOfParty;
	queue<int> knowTruth;
	vector<vector<int>> partyPeople;
	bool checkPeople[50] = { 0, };
	bool checkParty[50] = { 0, };
	int numberOfKnow;
	cin >> numberOfPeople >> numberOfParty;
	cin >> numberOfKnow;
	for(int i = 0; i < numberOfKnow; i++){
		int input;
		cin >> input;
		knowTruth.push(input);
	}

	for (int i = 0; i < numberOfParty; i++) {
		int N, input;
		vector<int> tmp;
		cin >> N;
		for (int j = 0; j < N; j++) {
			cin >> input;
			tmp.push_back(input);
		}

		partyPeople.push_back(tmp);
	}
	int result = numberOfParty;
	while (!knowTruth.empty()) {
		int now = knowTruth.front();
		knowTruth.pop();
		checkPeople[now] = true;

		for (int i = 0; i < partyPeople.size(); i++) {
			if (!checkParty[i]) {
					if (find(partyPeople[i].begin(), partyPeople[i].end(), now) != partyPeople[i].end()) {
						for (auto p : partyPeople[i]) {
							if (!checkPeople[p]) knowTruth.push(p);
						}
						checkParty[i] = true;
						result--;
					}
			}
		}
	}
	cout << result;

}