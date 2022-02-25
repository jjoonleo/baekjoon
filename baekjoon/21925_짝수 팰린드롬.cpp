#include<stdio.h>
#include<iostream>
#include<stack>

using namespace std;

bool checkPalindrome(int* a, int size);
int main() {

	int N, a[5000], pre = -1, result = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	for (int i = 1; i < N; i += 2) {
		if (checkPalindrome(a + pre + 1, i - pre)) {
			result++;
			pre = i;
		}
		if (i == N - 1 && i != pre) {
			result = -1;
		}

	}
	cout << result << endl;

}

bool checkPalindrome(int* a, int size) {
	/*for(int i = 0; i < size; i++){
		cout << a[i] << " ";
	}*/
	//cout << endl;
	stack<int> s;
	for (int i = 0; i < size / 2; i++) {
		s.push(a[i]);
	}
	for (int i = size / 2; i < size; i++) {
		//printf("%d: %d --- %d\n", i, s.top(), a[i]);
		if (s.top() != a[i]) return false;
		s.pop();
	}
	return true;
}