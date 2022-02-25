#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif


#define _USE_MATH_DEFINES

#include <iostream>
#include <complex>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

vector<complex<double>> FFT(vector<int> P, int n) {
	vector<int> P_0(n / 2), P_1(n / 2);
	vector<complex<double>> y_0(n / 2), y_1(n / 2), ret(n);
	complex<double> omega = polar(1.0, M_PI * 2 / n);
	complex<double> tmp(P[0]);


	if (n == 1) {		//길이가 1이면 리턴
		ret[0] = tmp;
		return ret;
	}
	for (int i = 0; i < n - P.size(); i++) {		//남는 부분 0으로 채우기
		P.push_back(0);
	}
	for (int i = 0; i < P.size(); i++) {		//짝수차항 홀수차항 분리 P(x) = P_0(x) + x*P_1(x)
		if (i % 2 == 0) {						//P_0: 짝수, P_1: 홀수
			P_0[i / 2] = P[i];
		}
		else {
			P_1[i / 2] = P[i];
		}
	}
	y_0 = FFT(P_0, n / 2);		//재귀

	y_1 = FFT(P_1, n / 2);
	for (int k = 0; k < n / 2; k++) {		//P값 계산
		ret[k] = y_0[k] + pow(omega, k) * y_1[k];
		ret[k + n / 2] = y_0[k] - pow(omega, k) * y_1[k];
	}

	return ret;
}

vector<complex<double>> IFFT(vector<complex<double>> P, int n) {
	vector<complex<double>> P_0(n / 2), P_1(n / 2);
	vector<complex<double>> y_0(n / 2), y_1(n / 2), ret(n);
	complex<double> omega = polar(1.0, M_PI * 2 / n);
	complex<double> tmp(P[0]);

	if (n == 1) {
		ret[0] = tmp;
		return ret;
	}
	for (int i = 0; i < n - P.size(); i++) {
		P.push_back(0);
	}
	for (int i = 0; i < P.size(); i++) {
		if (i % 2 == 0) {
			P_0[i / 2] = P[i];
		}
		else {
			P_1[i / 2] = P[i];
		}
	}
	y_0 = IFFT(P_0, n / 2);

	y_1 = IFFT(P_1, n / 2);
	for (int k = 0; k < n / 2; k++) {
		complex<double> tmpOmega = pow(omega, k);
		tmpOmega = conj(tmpOmega);
		ret[k] = y_0[k] + tmpOmega * y_1[k];
		ret[k + n / 2] = y_0[k] - tmpOmega * y_1[k];
	}

	return ret;
}


int findN(int N) {
	int i = 0;
	for (i = 0; pow(2, i) <= N; i++);

	return pow(2, i);
}

int main() {
	vector<int> P, P2, P3;
	vector<complex<double>> v, v2, v3;
	int N, tmp;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		P.push_back(tmp);
	}
	for (int i = 0; i < N; i++) {	//두배로 만들기 ex)1 2 3 4 -> 1 2 3 4 1 2 3 4
		P.push_back(P[i]);
	}
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		P2.push_back(tmp);
	}
	reverse(P2.begin(), P2.end());	//P2 뒤집기
	int times = findN(3 * N);	//가장 가까운 2의 제곱수 찾기
	//cout << "times:" << times << endl;

	v = FFT(P, times);		//fft 돌리기
	v2 = FFT(P2, times);
	for (int i = 0; i < v.size(); i++) {		//곱하기
		v3.push_back(v[i] * v2[i]);
	}
	v3 = IFFT(v3, times);		//다시 역변환
	double result = 0;
	for (auto i : v3) {
		if ((int)i.real())
			result = result > i.real() / times ? result : i.real() / times;		//최댓갑 찾기
	}
	cout << result << "\n";
}