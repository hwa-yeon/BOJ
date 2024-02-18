#include <iostream>
#include <vector>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<int> A(n);
	A[0] = 1;
	A[1] = 2;
	for (int i = 2; i < n; i++) {
		A[i] = (A[i - 2] + A[i - 1]) % 10007;
	}

	cout << A[n - 1] << "\n";

	return 0;
}
