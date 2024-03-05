#include <iostream>
#include <stack>
#include <string>
#include <cstring>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	cin >> str;

	int result = 0;
	char before = '(';
	stack<char> S;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') {
			S.push('(');
			before = '(';
		}
		else if (str[i] == ')') {
			if (before == '(') {
				S.pop();
				result += S.size();
				before = ')';
			}
			else if (before == ')') {
				S.pop();
				result += 1;
				before = ')';
			}
		}
	}

	cout << result << "\n";

	return 0;
}
