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

	vector<int> weight;
	weight.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> weight[i];
	}
	sort(weight.begin(), weight.end());

	int result = 0;
	for (int i = 1; i <= N; i++) {
		result = max(result, weight[N - i] * i);
	}

	cout << result << "\n";

	return 0;
}
