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

long long ccw(const Dot& A, const Dot& B, const Dot& C) {
	return 1LL * (B.x - A.x) * (C.y - A.y) - 1LL * (B.y - A.y) * (C.x - A.x);
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

int main() {
	int a, b;
	cin >> a >> b;
	Dot A(a, b);
	cin >> a >> b;
	Dot B(a, b);
	cin >> a >> b;
	Dot C(a, b);
	cin >> a >> b;
	Dot D(a, b);
	cout << cross(A, B, C, D);
}