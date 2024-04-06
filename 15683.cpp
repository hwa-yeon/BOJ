#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static int dx[] = { 0,1,0,-1 };
static int dy[] = { 1,0,-1,0 };

int N, M;
vector< vector<int> > input;

int cctv = 0;
int result = 0;

void check(int a, int b, int k) {
	while (true) {
		int x = a + dx[k % 4];
		int y = b + dy[k % 4];

		a = x;
		b = y;

		if (x < 0 || y < 0 || x >= N || y >= M) return;
		if (input[x][y] == 6) return;
		if (input[x][y] == 0) input[x][y] = -1;
	}
}

void func(int depth, int number) {

	if (depth == cctv) {
		int cnt = 0;
		for (int n = 0; n < N; n++) {
			for (int m = 0; m < M; m++) {
				if (input[n][m] == 0) cnt++;
			}
		}
		result = min(result, cnt);
		return;
	}

	for (int i = number; i < N * M; i++) {
		int a = i / M;
		int b = i % M;

		if (input[a][b] == 0 || input[a][b] == 6 || input[a][b] == -1) continue;

		vector< vector<int> > tmp;
		tmp.resize(N, vector<int>(M));
		for (int n = 0; n < N; n++) {
			for (int m = 0; m < M; m++) {
				tmp[n][m] = input[n][m];
			}
		}

		for (int k = 0; k < 4; k++) {
			if (input[a][b] == 1) {
				check(a, b, k);
			}
			else if (input[a][b] == 2) {
				check(a, b, k);
				check(a, b, k + 2);

			}
			else if (input[a][b] == 3) {
				check(a, b, k);
				check(a, b, k + 1);
			}
			else if (input[a][b] == 4) {
				check(a, b, k);
				check(a, b, k + 1);
				check(a, b, k + 2);
			}
			else if (input[a][b] == 5) {
				check(a, b, 0);
				check(a, b, 1);
				check(a, b, 2);
				check(a, b, 3);
			}
			func(depth + 1, i + 1);

			for (int n = 0; n < N; n++) {
				for (int m = 0; m < M; m++) {
					input[n][m] = tmp[n][m];
				}
			}
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	input.resize(N, vector<int>(M));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int num;
			cin >> num;
			input[i][j] = num;

			if (num >= 1 && num <= 5) cctv++;
			if (num == 0) result++;
		}
	}

	func(0, 0);
	cout << result << "\n";

	return 0;
}
