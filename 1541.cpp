#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	cin >> str;

	vector<int> A;

	int num = 0;
	char before = '-';
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '+') {
			if (before == '+') {
				A[A.size() - 1] += num;
			}
			else {
				A.push_back(num);
			}
			before = '+';
			num = 0;
		}
		else if (str[i] == '-') {
			if (before == '+') {
				A[A.size() - 1] += num;
			}
			else {
				A.push_back(num);
			}
			before = '-';
			num = 0;
		}
		else {
			num = num * 10 + (str[i] - '0');
		}
	}
	if (before == '+') {
		A[A.size() - 1] += num;
	}
	else {
		A.push_back(num);
	}

	int result = A[0];
	for (int i = 1; i < A.size(); i++) {
		result -= A[i];
	}

	cout << result << "\n";

	return 0;
}
