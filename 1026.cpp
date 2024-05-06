#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> A;
	vector<int> B;
	A.resize(N);
	B.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> B[i];
	}

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	int result = 0;
	for (int i = 0; i < N; i++) {
		result += A[i] * B[N - i - 1];
	}

	cout << result << "\n";

	return 0;
}
