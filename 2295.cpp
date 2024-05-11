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

	vector<int> input;
	input.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> input[i];
	}
	sort(input.begin(), input.end());

	vector<int> sum;
	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			sum.push_back(input[i] + input[j]);
		}
	}
	sort(sum.begin(), sum.end());

	int result = 0;
	int find = 0;
	for (int i = N - 1; i >= 0; i--) {
		for (int j = i - 1; j >= 0; j--) {
			if (binary_search(sum.begin(), sum.end(), input[i] - input[j])) {
				result = input[i];
				find = 1;
				break;
			}
		}
		if (find) break;
	}

	cout << result << "\n";

	return 0;
}
