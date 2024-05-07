#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	while (T--) {
		int N;
		cin >> N;

		vector<int> A;
		A.resize(N);

		for (int i = 0; i < N; i++) {
			cin >> A[i];
		}

		long long result = 0;
		int maxNum = 0;
		for (int i = N - 1; i >= 0; i--) {
			maxNum = max(maxNum, A[i]);
			result += maxNum - A[i];
		}

		cout << result << "\n";
	}

	return 0;
}
