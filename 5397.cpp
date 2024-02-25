#include <iostream>
#include <stack>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		string str;
		cin >> str;

		stack<char> left;
		stack<char> right;
		for (int j = 0; j < str.size(); j++) {
			char ch = str[j];
			if (ch == '<') {
				if (!left.empty()) {
					right.push(left.top());
					left.pop();
				}
			}
			else if (ch == '>') {
				if (!right.empty()) {
					left.push(right.top());
					right.pop();
				}
			}
			else if (ch == '-') {
				if (!left.empty()) {
					left.pop();
				}
			}
			else {
				left.push(ch);
			}
		}

		while (!left.empty()) {
			right.push(left.top());
			left.pop();
		}

		while (!right.empty()) {
			cout << right.top();
			right.pop();
		}

		cout << "\n";
	}

	return 0;
}
