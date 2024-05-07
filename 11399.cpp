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

	int sum = 0;
	int result = 0;
	for (int i = 0; i < N; i++) {
		sum += input[i];
		result += sum;
	}

	cout << result << "\n";

	return 0;
}
