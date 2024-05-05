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

	vector< pair<int, int> > input;
	vector<int> maxPay;
	input.resize(N + 2);
	maxPay.resize(N + 2);

	for (int i = 1; i <= N; i++) {
		cin >> input[i].first >> input[i].second;
	}

	maxPay[N + 1] = 0;
	if (input[N].first == 1) maxPay[N] = input[N].second;
	else maxPay[N] = 0;

	for (int i = N - 1; i >= 1; i--) {
		if (i + input[i].first - 1 <= N) {
			maxPay[i] = max(input[i].second + maxPay[i + input[i].first], maxPay[i + 1]);
		}
		else {
			maxPay[i] = maxPay[i + 1];
		}
	}

	cout << maxPay[1] << "\n";

	return 0;
}
