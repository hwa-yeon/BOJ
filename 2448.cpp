#include <iostream>
#include <vector>
using namespace std;

vector< vector<char> > V;

void star(int y, int x, int n) {
	
	if (n == 3) {
		V[y][x] = '*';
		V[y + 1][x - 1] = '*';
		V[y + 1][x + 1] = '*';
		V[y + 2][x - 2] = '*';
		V[y + 2][x - 1] = '*';
		V[y + 2][x] = '*';
		V[y + 2][x + 1] = '*';
		V[y + 2][x + 2] = '*';
		return;
	}

	star(y, x, n / 2);
	star(y + n / 2, x - n / 2, n / 2);
	star(y + n / 2, x + n / 2, n / 2);
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	V.resize(N, vector<char>(2 * N - 1, ' '));

	star(0, N - 1, N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 2 * N - 1; j++) {
			cout << V[i][j];
		}
		cout << "\n";
	}

	return 0;
}
