#include <iostream>
#include <vector>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector< vector<int> > A(N, vector<int>(10));

	for (int i = 0; i <= 9; i++) {
		A[0][i] = 1;
	}
	for (int i = 1; i < N; i++) {
		for (int j = 9; j >= 0; j--) {
			if (j == 9) {
				A[i][j] = A[i - 1][j];
			}
			else {
				A[i][j] = (A[i - 1][j] + A[i][j + 1]) % 10007;
			}
		}
	}
	int result = 0;
	for (int i = 0; i <= 9; i++) {
		result += A[N - 1][i];
	}
	cout << (result % 10007) << "\n";

	return 0;
}
