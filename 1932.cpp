#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector< vector<int> > input;
	vector< vector<int> > output;
	input.resize(n, vector<int>(n));
	output.resize(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> input[i][j];
		}
	}

	output[0][0] = input[0][0];
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) {
				output[i][j] = output[i - 1][j] + input[i][j];
			}
			else if (j == i) {
				output[i][j] = output[i - 1][j - 1] + input[i][j];
			}
			else {
				output[i][j] = max(output[i - 1][j], output[i - 1][j - 1]) + input[i][j];
			}
		}
	}

	int result = 0;
	for (int j = 0; j < n; j++) {
		result = max(result, output[n - 1][j]);
	}
	cout << result << "\n";

	return 0;
}
