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

	vector<int> A(N);
	vector<int> step(N);
	for (int i = 0; i < N; i++) {
		cin >> step[i];
	}

	A[0] = step[0];
	A[1] = step[0] + step[1];
	A[2] = max(step[0], step[1]) + step[2];
	for (int i = 3; i < N; i++) {
		A[i] = max(A[i - 3] + step[i - 1], A[i - 2]) + step[i];
	}
	
	cout << A[N - 1] << "\n";

	return 0;
}
