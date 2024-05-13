#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, S;
	cin >> N >> S;

	vector<int> input;
	input.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> input[i];
	}

	int start = 0;
	int end = 0;
	int sum = input[0];
	int result = 100001;
	while (start <= end) {
		if (sum >= S) {
			result = min(result, end - start + 1);

			sum -= input[start];
			start++;
		}
		else {
			if (end == N - 1) break;
			else {
				end++;
				sum += input[end];
			}
		}
	}

	if (result == 100001) cout << 0 << "\n";
	else cout << result << "\n";

	return 0;
}
