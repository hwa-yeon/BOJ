#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	
	vector<int> A;
	A.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}

	vector<int> B;
	B.resize(n);

	B[0] = A[0];
	B[1] = A[0] + A[1];
	B[2] = max(max(A[0] + A[2], A[1] + A[2]), A[0] + A[1]);
	for (int i = 3; i < n; i++) {
		B[i] = max(max(B[i - 2] + A[i], B[i - 3] + A[i - 1] + A[i]), B[i - 1]);
	}

	cout << B[n - 1] << "\n";

	return 0;
}
