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

	vector<int> input;
	input.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> input[i];
	}
	sort(input.begin(), input.end());

	int start = 0;
	int end = 0;
	int result = 2000000000;
	while (start <= end) {
		if (input[end] - input[start] >= M) {
			result = min(result, input[end] - input[start]);
			start++;
		}
		else if (end == N - 1) {
			start++;
		}
		else {
			end++;
		}
	}
	cout << result << "\n";

	return 0;
}
