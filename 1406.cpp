#include <iostream>
#include <string>
#include <cstring>
#include <stack>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	cin >> str;

	stack<char> left;
	stack<char> right;
	for (int i = 0; i < str.size(); i++) {
		left.push(str[i]);
	}

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		char a, b;
		cin >> a;

		if (a == 'L') {
			if (!left.empty()) {
				right.push(left.top());
				left.pop();
			}
		}
		else if (a == 'D') {
			if (!right.empty()) {
				left.push(right.top());
				right.pop();
			}
		}
		else if (a == 'B') {
			if (!left.empty()) {
				left.pop();
			}
		}
		else if (a == 'P') {
			cin >> b;
			left.push(b);
		}
	}

	while (!left.empty()) {
		right.push(left.top());
		left.pop();
	}

	while(!right.empty()) {
		cout << right.top();
		right.pop();
	}
	cout << "\n";

	return 0;
}
