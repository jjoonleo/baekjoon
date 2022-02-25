/*½ÇÆÐ*/

#include <stdio.h>
#include <iostream> 
#include <algorithm>
#include <queue>

using namespace std;

struct Package {
    int send;
    int recieve;
    int boxNumber;
};

bool compare(const Package& p1, const Package& p2) {
    if (p1.recieve == p2.recieve) {
        return p1.send > p2.send;
    }
    else
        return p1.recieve < p2.recieve;
}

int main() {
    Package p[10001];
    int capacities[2010] = { 0, };
    int N, capacity, M, result = 0;
    cin >> N >> capacity >> M;

    for (int i = 0; i < M; i++) {
        cin >> p[i].send >> p[i].recieve >> p[i].boxNumber;
    }

    sort(p, p + M, compare);

    result = min(p[0].boxNumber, capacity);
    for (int i = p[0].send; i < p[0].recieve; i++) {
        capacities[i] += result;
    }
    
    for (int i = 1; i < M; i++) {
        int largest = 0;
        for (int j = p[i].send; j < p[i].recieve; j++) {
            largest = max(capacities[j], largest);
        }
        for (int j = p[i].send; j < p[i].recieve; j++) {
            capacities[j] += min(p[i].boxNumber, capacity - largest);
        }
        result += min(p[i].boxNumber, capacity - largest);
    }

    cout << result;
    return 0;
}