#include<iostream>
#include<stack>
#include<cmath>
#include<algorithm>

using namespace std;

struct Dot {
	int x, y;
	int p, q;
	Dot() : x(0), y(0), p(1), q(1) {};
	Dot(int x1, int y1) : x(x1), y(y1), p(1), q(1) {};
};

bool cmp(Dot d1, Dot d2) {
	if (1LL * d1.q * d2.p != 1LL * d1.p * d2.q) {
		return 1LL * d1.q * d2.p < 1LL * d1.p * d2.q;
	}

	if (d1.y == d2.y) {
		return d1.x < d2.x;
	}
	else
		return d1.y < d2.y;
}

long long ccw(const Dot& A, const Dot& B, const Dot& C) {
	return 1LL * (B.x - A.x) * (C.y - A.y) - 1LL * (B.y - A.y) * (C.x - A.x);
}


Dot dots[1000000];

int main() {
	int numberOfDots;
	int inputX, inputY;
	cin >> numberOfDots;
	for (int i = 0; i < numberOfDots; i++) {
		cin >> inputX >> inputY;
		dots[i] = Dot(inputX, inputY);
	}

	sort(dots, dots + numberOfDots, cmp);

	for (int i = 0; i < numberOfDots; i++) {
		dots[i].p = dots[i].x - dots[0].x;
		dots[i].q = dots[i].y - dots[0].y;
	}

	sort(dots+1, dots + numberOfDots, cmp);

	stack<int> s;
	s.push(0);
	s.push(1);
	int nextDotIndex = 2, preDotIndex, curDotIndex;
	

	while (nextDotIndex < numberOfDots) {

		while (s.size() >= 2) {
			curDotIndex = s.top();
			s.pop();
			preDotIndex = s.top();

			if (ccw(dots[preDotIndex], dots[curDotIndex], dots[nextDotIndex]) > 0) {
				s.push(curDotIndex);
				break;
			}
		}
		s.push(nextDotIndex++);
	}

	cout << s.size();
}