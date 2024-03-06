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

	stack<char> S;
	int temp = 1;
	int answer = 0;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') {
			S.push('(');
			temp *= 2;
		}
		else if (str[i] == '[') {
			S.push('[');
			temp *= 3;
		}
		else if (str[i] == ')') {
			if (S.empty() || S.top() != '(') {
				answer = 0;
				break;
			}

			if (str[i - 1] == '(') {
				answer += temp;
			}
			
			S.pop();
			temp /= 2;
		}
		else if (str[i] == ']') {
			if (S.empty() || S.top() != '[') {
				answer = 0;
				break;
			}

			if (str[i - 1] == '[') {
				answer += temp;
			}

			S.pop();
			temp /= 3;
		}
	}

	if (!S.empty()) {
		answer = 0;
	}
	cout << answer << "\n";

	return 0;
}
