#include <iostream>
#include <stack>
#include <string>
#include <cstring>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true) {
		string str;
		getline(cin, str);

		if (str == ".") break;

		stack<char> S;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '(') {
				S.push('(');
			}
			else if (str[i] == ')') {
				if (S.empty()) {
					S.push(')');
					break;
				}
				else {
					if (S.top() == '(') {
						S.pop();
					}
					else {
						break;
					}
				}
			}
			else if (str[i] == '[') {
				S.push('[');
			}
			else if (str[i] == ']') {
				if (S.empty()) {
					S.push(']');
					break;
				}
				else {
					if (S.top() == '[') {
						S.pop();
					}
					else {
						break;
					}
				}
			}
		}

		if (S.empty()) {
			cout << "yes" << "\n";
		}
		else {
			cout << "no" << "\n";
		}
	}

	return 0;
}
