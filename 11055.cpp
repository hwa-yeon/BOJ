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

	vector<int> in;
	vector<int> sum;
	in.resize(N);
	sum.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> in[i];
	}

	sum[0] = in[0];
	for (int i = 1; i < N; i++) {
		sum[i] = in[i];
		for (int j = 0; j < i; j++) {
			if (in[j] < in[i]) {
				sum[i] = max(sum[i], sum[j] + in[i]);
			}
		}
	}
	sort(sum.begin(), sum.end());

	cout << sum[N - 1] << "\n";

	return 0;
}
