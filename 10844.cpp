#include <iostream>
#include <vector>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector< vector<int> > V;
	V.resize(N, vector<int>(10));

	for (int j = 0; j <= 9; j++) {
		if (j == 0) V[0][j] = 0;
		else V[0][j] = 1;
	}
	

	for (int i = 1; i < N; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j == 0) V[i][j] = V[i - 1][j + 1];
			else if (j == 9) V[i][j] = V[i - 1][j - 1];
			else V[i][j] = V[i - 1][j - 1] + V[i - 1][j + 1];

			V[i][j] %= 1000000000;
		}
	}

	int result = 0;
	for (int j = 0; j <= 9; j++) {
		result = (result + V[N - 1][j]) % 1000000000;
	}

	cout << result << "\n";

	return 0;
}
