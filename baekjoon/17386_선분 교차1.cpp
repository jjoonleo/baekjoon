#include<iostream>
#include<deque>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

struct Dot {
	long long x, y;
	Dot() : x(0), y(0) {};
	Dot(int x1, int y1) : x(x1), y(y1) {};
};

long long ccw(const Dot& A, const Dot& B, const Dot& C) {
	long long t = (A.x - B.x) * (C.y - B.y) - (A.y - B.y) * (C.x - B.x);
	return (t < 0) - (t > 0);

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
			&& max(A.y, B.y) >= min(C.y, D.y)
			&& max(C.y, D.y) >= min(A.y, B.y)) {
			return true;

		}
		else if (max(A.x, B.x) >= min(C.x, D.x)
			&& max(C.x, D.x) >= min(A.x, B.x)) {
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
	long long a, b;
	cin >> a >> b;
	Dot A(a, b);
	cin >> a >> b;
	Dot B(a, b);
	cin >> a >> b;
	Dot C(a, b);
	cin >> a >> b;
	Dot D(a, b);
	cout << (cross(A, B, C, D) & cross(C, D, A, B)) << "\n";
}