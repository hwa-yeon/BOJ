#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N;
vector< vector<int> > input;

void func(int y, int x, int n) {

	bool same = true;
	for (int i = y; i < y + n; i++) {
		for (int j = x; j < x + n; j++) {
			if (input[i][j] != input[y][x]) {
				same = false;
				break;
			}
		}
		if (!same) break;
	}

	if (same) {
		cout << input[y][x];
		return;
	}

	cout << "(";
	func(y, x, n / 2);
	func(y, x + n / 2, n / 2);
	func(y + n / 2, x, n / 2);
	func(y + n / 2, x + n / 2, n / 2);
	cout << ")";
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	input.resize(N, vector<int>(N));

	for (int i = 0; i < N; i++) {
		string num;
		cin >> num;
		for (int j = 0; j < N; j++) {
			input[i][j] = num[j] - '0';
		}
	}

	func(0, 0, N);

	return 0;
}
