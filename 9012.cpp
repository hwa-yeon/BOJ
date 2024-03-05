#include <iostream>
#include <stack>
#include <string>
#include <cstring>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	while (T--) {
		string str;
		cin >> str;

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
					S.pop();
				}
			}
		}

		if (S.empty()) {
			cout << "YES" << "\n";
		}
		else {
			cout << "NO" << "\n";
		}
	}

	return 0;
}
