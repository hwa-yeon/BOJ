#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector< vector<int> > A;

	int N;
	cin >> N;

	A.resize(N, vector<int>(3));

	for (int i = 0; i < N; i++) {
		int R, G, B;
		cin >> R >> G >> B;
		
		if (i == 0) {
			A[0][0] = R;
			A[0][1] = G;
			A[0][2] = B;

			continue;
		}

		A[i][0] = min(A[i - 1][1], A[i - 1][2]) + R;
		A[i][1] = min(A[i - 1][0], A[i - 1][2]) + G;
		A[i][2] = min(A[i - 1][0], A[i - 1][1]) + B;
	}

	int result = min(A[N - 1][0], min(A[N - 1][1], A[N - 1][2]));
	cout << result << "\n";

	return 0;
}
