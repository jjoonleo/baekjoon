#include<iostream>
#include<stack>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

struct Dot {
	int x, y;
	int p, q;
	int index;
	Dot() : x(0), y(0), p(1), q(1), index(-1) {};
	Dot(int x1, int y1, int index1) : x(x1), y(y1), p(1), q(1), index(index1) {};
};

bool cmp(Dot d1, Dot d2) {
		if (d1.y == d2.y) {
		return d1.x < d2.x;
	} 
	else
		return d1.y < d2.y;
}

bool cmp2(Dot d1, Dot d2) {
		if (1LL * d1.q * d2.p == 1LL * d1.p * d2.q && 1LL * d1.p * d1.q < 0) {
			return d1.y < d2.y;
		}
		return 1LL * d1.q * d2.p < 1LL * d1.p * d2.q;
}

long long ccw(const Dot& A, const Dot& B, const Dot& C) {
	return 1LL * (B.x - A.x) * (C.y - A.y) - 1LL * (B.y - A.y) * (C.x - A.x);
}

int main() {
	int numberOfDots;
	int inputX, inputY;
	int numberOfTestcase;
	vector<Dot> dots;
	cin >> numberOfTestcase;
	for (int t = 0; t < numberOfTestcase; t++) {
		dots.clear();
		cin >> numberOfDots;
		for (int i = 0; i < numberOfDots; i++) {
			cin >> inputX >> inputY;
			dots.push_back(Dot(inputX, inputY, i));
		}

		sort(dots.begin(), dots.end(), cmp);

		for (int i = 0; i < numberOfDots; i++) {
			dots[i].p = dots[i].x - dots[0].x;
			dots[i].q = dots[i].y - dots[0].y;
		}

		stable_sort(dots.begin() + 1, dots.end(), cmp2);

		int cnt = 0, i = dots.size() - 1;
		while (ccw(dots[0], dots.back(), dots[i])==0) {
			i--;
			cnt++;
		}

		reverse(dots.end() - cnt, dots.end());

		for (int i = 0; i < numberOfDots; i++)
		{
			cout << dots[i].index << " ";

		}
		cout << "\n";
	}
}