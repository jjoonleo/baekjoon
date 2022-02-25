#include <iostream>
#include <string>

using namespace std;

template<typename T>
struct list
{
	T val;
	list* next;
	list(T val) : val(val), next(NULL) {};
	list() : val(NULL), next(NULL) {};
};

template<typename T>
class stack
{
	list<T>* head = NULL;
	int length = 0;
public:
	void push(T val) {
		list<T>* node = new list<T>;
		node->val = val;
		node->next = head;
		head = node;
		length++;
	}
	void pop() {
		if (length) {
			head = head->next;
			length--;
		}
	}
	T top() {
		if (length)
			return head->val;
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
			cout << q.empty() << endl;
		}
		else if (s == "top") {
			if (q.size())
				cout << q.top() << endl;
			else
				cout << -1 << endl;
		}
	}
}