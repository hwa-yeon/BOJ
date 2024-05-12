#include <iostream>
#include <vector>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	vector<long long> A;
	A.resize(1000000);

	A[0] = 1;
	A[1] = 2;
	A[2] = 4;
	for (int i = 3; i < 1000000; i++) {
		A[i] = (A[i - 3] + A[i - 2] + A[i - 1]) % 1000000009;
	}

	while (T--) {
		int n;
		cin >> n;

		cout << A[n - 1] << "\n";
	}

	return 0;
}
