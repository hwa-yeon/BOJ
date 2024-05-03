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

	vector <long long> input;
	input.resize(N);

	for (int i = 0; i < N; i++) {
		long long num;
		cin >> num;
		input[i] = num;
	}
	sort(input.begin(), input.end());

	long long before = input[0];
	int count = 1;
	long long maxval = 0;
	int maxcount = 0;

	for (int i = 1; i < N; i++) {
		if (before == input[i]) {
			count++;
		}
		else {
			if (maxcount < count) {
				maxcount = count;
				maxval = before;
			}
			count = 1;
		}

		before = input[i];
	}

	if (maxcount < count) {
		maxcount = count;
		maxval = before;
	}

	cout << maxval << "\n";

	return 0;
}
