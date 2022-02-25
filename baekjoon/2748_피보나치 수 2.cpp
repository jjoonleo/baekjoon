#include<stdio.h>
#include<iostream>

using namespace std;

int main() {
	int n;
	long long f = 0, s = 1;
	long long tmp;
	scanf("%d", &n);
	if (n == 0) {
		printf("0");
		return 0;
	}
	for (int i = 0; i < n - 1; i++) {
		tmp = f;
		f = s;
		s = tmp + s;


	}printf("%lld ", s);
}