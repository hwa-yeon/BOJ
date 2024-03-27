#include <iostream>
#include <vector>
using namespace std;

static int N;
static vector< vector<int> > input;
int zero = 0;
int one = 0;
int _one = 0;

void func(int x, int y, int n) {
	bool same = true;
	for (int i = y; i < y + n; i++) {
		for (int j = x; j < x + n; j++) {
			if (input[y][x] != input[i][j]) {
				same = false;
				break;
			}
		}
		if (!same) {
			break;
		}
	}

	if (same) {
		if (input[y][x] == 0) {
			zero++;
			return;
		}
		else if (input[y][x] == 1) {
			one++;
			return;
		}
		else if (input[y][x] == -1) {
			_one++;
			return;
		}
	}

	func(x, y, n / 3);
	func(x + n / 3, y, n / 3);
	func(x + (n / 3) * 2, y, n / 3);

	func(x, y + n / 3, n / 3);
	func(x + n / 3, y + n / 3, n / 3);
	func(x + (n / 3) * 2, y + n / 3, n / 3);

	func(x, y + (n / 3) * 2, n / 3);
	func(x + n / 3, y + (n / 3) * 2, n / 3);
	func(x + (n / 3) * 2, y + (n / 3) * 2, n / 3);
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

	cout << _one << "\n";
	cout << zero << "\n";
	cout << one << "\n";

	return 0;
}
