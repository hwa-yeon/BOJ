#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector< vector<int> > input;
vector<bool> visited1;
vector<bool> visited2;
int result = 0;

void func(int depth, int size, bool color) {

	if (depth == (N * N)) {
		result = max(result, size);
		return;
	}

	bool flag = false;
	for (int i = depth; i < N * N; i++) {
		int x = i / N;
		int y = i % N;
		if (color && (x + y) % 2 != 0) continue;
		if (!color && (x + y) % 2 == 0) continue;

		if (input[x][y] && !visited1[x + y] && !visited2[x - y + N - 1]) {
			visited1[x + y] = true;
			visited2[x - y + N - 1] = true;
			flag = true;

			func(i + 1, size + 1, color);

			visited1[x + y] = false;
			visited2[x - y + N - 1] = false;
		}
	}
	if (!flag) {
		func(N * N, size, color);
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	input.resize(N, vector<int>(N));
	visited1.resize(2 * N - 1, false);
	visited2.resize(2 * N - 1, false);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int num;
			cin >> num;
			input[i][j] = num;
		}
	}

	func(0, 0, true);
	int temp = result;
	result = 0;
	func(1, 0, false);
	cout << result + temp << "\n";

	return 0;
}
