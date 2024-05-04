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

	vector<int> input;
	vector<int> output;
	input.resize(n);
	output.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> input[i];
	}

	output[0] = input[0];
	for (int i = 1; i < n; i++) {
		output[i] = max(input[i], input[i] + output[i - 1]);
	}
	sort(output.begin(), output.end());

	cout << output[n - 1] << "\n";

	return 0;
}
