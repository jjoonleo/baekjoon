#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

int check[21][10001] = { 0, };
int coin(int price, vector<int>& coins, int pre);

int main() {
	int n, t, price;
	vector<int> coins;
	cin >> t;
	for (int i = 0; i < t; i++) {
		
		cin >> n;
		int tmp = 0;
		
		for (int j = 0; j < n; j++) {
			cin >> tmp;
			coins.push_back(tmp);
		}
		cin >> price;
		for (int j = 0; j <= price; j++) {
			for (int k = 0; k <= n; k++) {
				check[k][j] = 0;
			}

		}
		/*for(auto c: coins){
			cout << c << " ";
		}
		cout << "\n";*/
		cout << coin(price, coins, 0) << "\n";
		
		coins.clear();
	}
}

int coin(int price, vector<int>& coins, int pre) {
	//cout<<price<<"\n";

	if (price < 0) {
		return 0;
	}
	else if (price == 0) {
		return 1;
	}
	if (check[pre][price] != 0) {
		return check[pre][price];
	}
	int result = 0;
	for (int c = pre; c < coins.size(); c++) {
		if (price < coins[c]) break;
		result += coin(price - coins[c], coins, c);
	
	}
	check[pre][price] = result;
	return result;
}