#include <iostream>
#include <string>

using namespace std;

template<typename T>
struct list
{
	T val;
	list* next;
	list(T val) : val(val), next(NULL) {}
};

template<typename T>
class stack
{
	list<T> head;
	int length = 0;
public:
	void push(T val) {
		list<T> node(val);
		node.next = head.next;
		head.next = node;
		head = node;
		size++;
	}
	void pop(T val) {
		node = head;

	}
	T top() {
		return head.next.val;
	}
	int size() {
		return size;
	}
	bool empty() {
		if (size) return false;
		else return true;
	}

};
int main() {
	int n, input;
	string s;
	stack<int> q;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (s == "push") {
			cin >> input;
			q.push(input);
		}
		else if (s == "pop") {
			if (q.size()) {
				cout << q.top() << endl;
				q.pop();
			}
			else
				cout << -1 << endl;

		}
		else if (s == "size") {
			cout << q.size() << endl;
		}
		else if (s == "empty") {
			cout << q.empty() 2<< endl;
		}
		else if (s == "top") {
			if (q.size())
				cout << q.top() << endl;
			else
				cout << -1 << endl;
		}
	}
}