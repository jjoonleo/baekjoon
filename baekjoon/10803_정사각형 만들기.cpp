#include <stdio.h>
#include <iostream>

using namespace std;

int square(int h, int w);
int check[10001][101] = { 0, };

int main() {
	int h, w;
	cin >> h;
	cin >> w;
	cout << square(h, w);
}

int square(int h, int w) {
	if (h < w) {
		int tmp = w;
		w = h;
		h = tmp;
	}


	if (w == 1)
		return h;
	else if (w == 2) {
		return h / 2 + (h % 2) * 2;
	}
	else if (w == 3) {
		if (h % 3 == 0)
			return h / 3;
		else
			return h / 3 + 3;
	}
	else if (w == h)
		return 1;
	else if (check[h][w] != 0) {
		return check[h][w];
	}

	int result = 987654321;

	if (h >= w * 3) {
		result = min(result, square(h - w, w) + 1);
	}
	else {
		for (int i = 1; i <= w / 2; i++) {
			result = min(result, square(h, i) + square(h, w - i));
		}
		for (int i = 1; i <= h / 2; i++) {
			result = min(result, square(i, w) + square(h - i, w));
		}
	}
	check[h][w] = result;
	return result;
}
