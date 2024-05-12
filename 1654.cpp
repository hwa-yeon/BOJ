#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int K, N;
vector<int> input;

bool solve(int leng) {
	int sum = 0;
	for (int i = 0; i < K; i++) {
		sum += input[i] / leng;
	}

	if (sum >= N) return true;
	else return false;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> K >> N;
	input.resize(K);

	for (int i = 0; i < K; i++) {
		cin >> input[i];
	}

	long long start = 0;
	long long end = pow(2, 31);
	while (start < end) {
		long long mid = (start + end + 1) / 2;
		if (solve(mid)) start = mid;
		else end = mid - 1;
	}

	cout << start << "\n";

	return 0;
}
