#include<stdio.h>
#include<iostream>

using namespace std;

int factorial(int N);

int main() {
	int N;
	cin >> N;
	printf("%d", factorial(N));
}

int factorial(int N) {
	if (N > 1) {
		return N * factorial(N - 1);
	}
	return 1;
}
