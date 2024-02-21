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

	vector<int> input(N + 1, 0);
	vector<int> output(N + 1, 0);

	for (int i = 1; i <= N; i++) {
		cin >> input[i];
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			output[i] = max(output[i], output[i - j] + input[j]);
		}
	}

	cout << output[N] << "\n";

	return 0;
}
