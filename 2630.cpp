#include <iostream>
#include <vector>
using namespace std;

int N;
vector< vector<int> > input;
int white = 0;
int blue = 0;

void func(int y, int x, int n) {

	bool same = true;
	for (int i = y; i < y + n; i++) {
		for (int j = x; j < x + n; j++) {
			if (input[y][x] != input[i][j]) {
				same = false;
				break;
			}
		}
		if (!same) break;
	}

	if (same) {
		if (input[y][x] == 0) {
			white++;
			return;
		}
		else if (input[y][x] == 1) {
			blue++;
			return;
		}
	}

	func(y, x, n / 2);
	func(y, x + n / 2, n / 2);
	func(y + n / 2, x, n / 2);
	func(y + n / 2, x + n / 2, n / 2);
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	input.resize(N, vector<int>(N));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int num;
			cin >> num;
			input[i][j] = num;
		}
	}

	func(0, 0, N);
	cout << white << "\n";
	cout << blue << "\n";

	return 0;
}
