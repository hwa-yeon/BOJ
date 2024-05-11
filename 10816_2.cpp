#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	vector<int> A;

	cin >> N;
	A.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());

	cin >> M;
	while (M--) {
		int find;
		cin >> find;

		cout << upper_bound(A.begin(), A.end(), find) - lower_bound(A.begin(), A.end(), find) << " ";
	}
	cout << "\n";

	return 0;
}
