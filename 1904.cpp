#include <iostream>
#include <vector>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> A(N);
	A[0] = 1;
	A[1] = 2;
	for (int i = 2; i < N; i++) {
		A[i] = (A[i - 2] + A[i - 1]) % 15746;
	}

	cout << A[N - 1] << "\n";

	return 0;
}
