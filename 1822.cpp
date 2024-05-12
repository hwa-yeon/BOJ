#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<int> A;
	A.resize(N);
	vector<int> B;
	B.resize(M);

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());

	for (int i = 0; i < M; i++) {
		cin >> B[i];
	}
	sort(B.begin(), B.end());

	vector<int> result;
	for (int i = 0; i < N; i++) {
		if (binary_search(B.begin(), B.end(), A[i])) continue;
		result.push_back(A[i]);
	}

	cout << result.size() << "\n";
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	cout << "\n";

	return 0;
}
