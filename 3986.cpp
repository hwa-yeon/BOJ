#include <iostream>
#include <stack>
#include <string>
#include <cstring>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	
	int result = 0;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;

		stack<char> S;
		for (int j = 0; j < str.length(); j++) {
			if (S.empty()) {
				S.push(str[j]);
			}
			else {
				if (str[j] == S.top()) {
					S.pop();
				}
				else {
					S.push(str[j]);
				}
			}
		}

		if (S.empty()) {
			result++;
		}
	}

	cout << result << "\n";

	return 0;
}
