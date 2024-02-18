#include <iostream>
#include <vector>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> A(12);
	A[1] = 1;
	A[2] = 2;
	A[3] = 4;
	for (int i = 4; i <= 11; i++) {
		A[i] = A[i - 3] + A[i - 2] + A[i - 1];
	}

	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int n;
		cin >> n;
		cout << A[n] << "\n";
	}

	return 0;
}
