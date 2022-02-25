#include <iostream>
#include <string>

using namespace std;

template<typename T>
struct node
{
	T val;
	node* next;
	node(T val) : val(val), next(NULL) {};
	node() : val(NULL), next(NULL) {};
};

template<typename T>
class queue
{
private:
	node<T>* frontNode;
	node<T>* rearNode;
	int length;

public:
	queue() {
		frontNode = NULL;
		rearNode = NULL;
		length = 0;
	}

	void push(T val) {
		node<T>* curNode = new node<T>;
		curNode->val = val;
		if (length == 0) {
			frontNode = curNode;
		}
		else {
			rearNode->next = curNode;
		}
		rearNode = curNode;
		length++;

	}
	void pop() {
		if (length) {
			frontNode = frontNode->next;
			length--;
		}
	}
	T front() {
		if (length)
			return frontNode->val;
		else return NULL;
	}
	T back() {
		if (length)
			return rearNode->val;
		else return NULL;
	}
	int size() {
		return length;
	}
	bool empty() {
		if (length)
			return false;
		else
			return true;
	}
};
int main() {
	int n, input;
	string s;
	queue<int> q;
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (s == "push") {
			cin >> input;
			q.push(input);
		}
		else if (s == "pop") {
			if (q.size()) {
				cout << q.front() << "\n";
				q.pop();
			}
			else
				cout << -1 << "\n";

		}
		else if (s == "size") {
			cout << q.size() << "\n";
		}
		else if (s == "empty") {
			cout << q.empty() << "\n";
		}
		else if (s == "front") {
			if (q.size())
				cout << q.front() << "\n";
			else
				cout << -1 << "\n";
		}
		else if (s == "back") {
			if (q.size())
				cout << q.back() << "\n";
			else
				cout << -1 << "\n";
		}
	}
}