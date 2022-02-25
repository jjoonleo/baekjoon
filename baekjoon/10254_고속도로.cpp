#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

struct Dot {
	long long x, y;
	long long p, q;
	Dot() : x(0), y(0), p(1), q(1) {};
	Dot(long long x1, long long y1) : x(x1), y(y1), p(1), q(1) {};
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
	return (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);
}

long long cccw( Dot A,  Dot B,  Dot C, Dot D) {
	D.x -= C.x - B.x;
	D.y -= C.y - B.y;
	return ccw(A, B, D);
}

long long dist(Dot a, Dot b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
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
}


int main() {
	int inputX, inputY;
	int numberOfDots;
	vector<Dot> dots;
	deque<int> convex;
	int testcaseNumber;
	cin >> testcaseNumber;
	for (int t = 0; t < testcaseNumber; t++) {
		dots.clear();
		convex.clear();
		cin >> numberOfDots;
		for (int i = 0; i < numberOfDots; i++) {
			cin >> inputX >> inputY;
			dots.push_back(Dot(inputX, inputY));
		}

		convexHull(dots, convex);
		int a, b, c = convex[1], d = convex[2];
		long long maxDist = 0;
		Dot resultDot1, resultDot2;
		for(int i = 0; i < convex.size();i++){
			a = convex[i];
			b = (a + 1)%(convex.size()-1);
			while (d != a && cccw(dots[a], dots[b], dots[c], dots[d]) > 0) {
				if (maxDist < dist(dots[a], dots[c])) {
					resultDot1 = dots[a];
					resultDot2 = dots[c];
					maxDist = dist(dots[a], dots[c]);
				}
				c = (c + 1) % (convex.size()-1);
				d = (c + 1) % (convex.size()-1);
			}
			if (maxDist < dist(dots[a], dots[c])) {
				resultDot1 = dots[a];
				resultDot2 = dots[c];
				maxDist = dist(dots[a], dots[c]);
			}
		}
		printf("%lld %lld %lld %lld\n", resultDot1.x, resultDot1.y, resultDot2.x, resultDot2.y);
	}
}