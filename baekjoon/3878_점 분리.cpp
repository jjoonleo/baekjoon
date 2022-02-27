#include<iostream>
#include<deque>
#include<cmath>
#include<vector>
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

void convexHull(vector<Dot>& dots, deque<int>& s) {
	if (dots.size() <= 3) {
		for (int i = 0; i < dots.size(); i++) {
			s.push_back(i);
		}
		return;
	}
	int numberOfDots = dots.size();

	sort(dots.begin(), dots.end(), cmp);

	for (int i = 0; i < numberOfDots; i++) {
		dots[i].p = dots[i].x - dots[0].x;
		dots[i].q = dots[i].y - dots[0].y;
	}

	sort(dots.begin() + 1, dots.end(), cmp);

	s.push_back(0);
	s.push_back(1);
	int nextDotIndex = 2, preDotIndex, curDotIndex;


	while (nextDotIndex < numberOfDots) {

		while (s.size() >= 2) {
			curDotIndex = s.back();
			s.pop_back();
			preDotIndex = s.back();

			if (ccw(dots[preDotIndex], dots[curDotIndex], dots[nextDotIndex]) > 0) {
				s.push_back(curDotIndex);
				break;
			}
		}
		s.push_back(nextDotIndex++);
	}

	//cout << s.size();
}

bool cross(Dot& A, Dot& B, Dot& C, Dot& D) {
	if ((A.x == B.x && A.y == B.y) && (C.x == D.x && C.y == D.y)) return false;
	else if (A.x == B.x && A.y == B.y) {
		if (ccw(C, D, A) == 0 && A.x > min(D.x, C.x) && A.x < max(D.x, C.x))
			return true;
		else
			return false;
	}
	else if (C.x == D.x && C.y == D.y) {
		if (ccw(A, B, C) == 0 && C.x > min(A.x, B.x) && C.x < max(A.x, B.x))
			return true;
		else
			return false;
	}
	else if (ccw(A, B, C) * ccw(A, B, D) == 0
		&& ccw(C, D, A) * ccw(C, D, B) == 0) {
		if (A.x == B.x
			&& max(A.y, B.y) > min(C.y, D.y)
			&& max(C.y, D.y) > min(A.y, B.y)) {
			return true;

		}
		else if (max(A.x, B.x) > min(C.x, D.x)
			&& max(C.x, D.x) > min(A.x, B.x)) {
			return true;
		}
		return false;
	}

	else if (ccw(A, B, C) * ccw(A, B, D) <= 0
		&& ccw(C, D, A) * ccw(C, D, B) <= 0) {
		return true;
	}
	return false;
}

bool isInside(vector<Dot> dots, deque<int> convex, Dot dot) {
	int crosses = 0;
	for (int i = 0; i < convex.size() - 1; i++) {
		Dot curdot = dots[convex[i]];
		Dot nextdot = dots[convex[i + 1]];
		if ((curdot.y > dot.y) != (nextdot.y > dot.y)) {
			double intersectionX = (nextdot.x - curdot.x) * (dot.y - curdot.y) / (nextdot.y - curdot.y) + curdot.x;

			if (intersectionX > dot.x) {
				crosses++;
			}
		}
	}
	return crosses % 2 > 0;
}

int main() {
	int inputX, inputY;
	int numberOfBlackDots, numberOfWhiteDots;
	vector<Dot> bdots, wdots;
	deque<int> bconvex, wconvex;
	int testcaseNumber;
	cin >> testcaseNumber;
	for (int t = 0; t < testcaseNumber; t++) {
		bdots.clear(); wdots.clear();
		bconvex.clear(); wconvex.clear();
		cin >> numberOfBlackDots >> numberOfWhiteDots;
		for (int i = 0; i < numberOfBlackDots; i++) {
			cin >> inputX >> inputY;
			bdots.push_back(Dot(inputX, inputY));
		}

		convexHull(bdots, bconvex);

		for (int i = 0; i < numberOfWhiteDots; i++) {
			cin >> inputX >> inputY;
			wdots.push_back(Dot(inputX, inputY));
		}
		convexHull(wdots, wconvex);
		if (bdots.size() == 1 && wdots.size() == 1) {
			cout << "YES" << "\n";
			continue;
		}

		wconvex.push_back(wconvex[0]);
		bconvex.push_back(bconvex[0]);

		bool breakall = false;
		for (int b = 0; b < bconvex.size() - 1; b++) {
			for (int w = 0; w < wconvex.size() - 1; w++) {
				if (cross(bdots[bconvex[b]], bdots[bconvex[b + 1]], wdots[wconvex[w]], wdots[wconvex[w + 1]])) {
					cout << "NO" << "\n";
					breakall = true;
					break;
				}
				if (breakall) break;
			}
			if (breakall) break;
		}
		if (breakall) continue;

		bool bcheck = true;
		bool wcheck = true;
		if (wdots.size() > 2) {
			for (int b = 0; b < bconvex.size() - 1; b++) {
				bcheck = !isInside(wdots, wconvex, bdots[bconvex[b]]);
			}
			if (!bcheck) {
				cout << "NO" << "\n";
				continue;
			}
		}
		if (bdots.size() > 2) {
			for (int w = 0; w < wconvex.size() - 1; w++) {
				wcheck = !isInside(bdots, bconvex, wdots[wconvex[w]]);
			}
			if (!wcheck) {
				cout << "NO" << "\n";
				continue;
			}
		}
		cout << "YES" << "\n";
	}
}
