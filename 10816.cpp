#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> A;
int N, M;

int lowerIdx(int find, int leng) {
	int start = 0;
	int end = leng;
	while (start < end) {
		int mid = (start + end) / 2;
		if (A[mid] >= find) {
			end = mid;
		}
		else {
			start = mid + 1;
		}
	}

	return start;
}

int upperIdx(int find, int leng) {
	int start = 0;
	int end = leng;
	while (start < end) {
		int mid = (start + end) / 2;
		if (A[mid] > find) {
			end = mid;
		}
		else {
			start = mid + 1;
		}
	}

	return start;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

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

		cout << upperIdx(find, N) - lowerIdx(find, N) << " ";
	}
	cout << "\n";

	return 0;
}
