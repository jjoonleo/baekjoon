#include<stdio.h>
#include<stack>
#include<iostream>
using namespace std;
int main(void) {
	stack<int> stack;
	bool tmp;
	int ret = 0;
	char str[100000];

	scanf("%s", str);
	for (int i = 0; str[i] != 0; i++) {
		if (str[i] == '(') {
			stack.push(1);
			//printf("%d\n",ret);
			tmp = 1;
		}
		else if (str[i] == ')' && tmp == 1) {
			stack.pop();
			ret += stack.size();
			//printf("%d  %d\n",stack.size(),ret);
			tmp = 0;
		}
		else if (str[i] == ')' && tmp == 0) {
			ret += 1;
			//printf("%d\n",ret);
			stack.pop();
		}

	}printf("%d", ret);

}