#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int M, N;
vector<int> snack;

bool solve(long long leng) {
	int sum = 0;
	for (int i = 0; i < N; i++) {
		sum += snack[i] / leng;
	}
	if (sum >= M) return true;
	else return false;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M >> N;
	snack.resize(N);
	
	int maxLeng = 0;
	for (int i = 0; i < N; i++) {
		cin >> snack[i];
		maxLeng = max(maxLeng, snack[i]);
	}

	long long int start = 0;
	long long int end = maxLeng;
	while (start < end) {
		long long mid = (start + end + 1) / 2;
		if (solve(mid)) start = mid;
		else end = mid - 1;
	}
	
	cout << start << "\n";

	return 0;
}
