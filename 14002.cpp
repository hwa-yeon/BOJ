#include <iostream>
#include <vector>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> input;
	vector<int> count;
	vector<int> before;
	input.resize(N);
	count.resize(N);
	before.resize(N, -1);

	for (int i = 0; i < N; i++) {
		cin >> input[i];
	}

	count[0] = 1;
	for (int i = 1; i < N; i++) {
		count[i] = 1;
		for (int j = 0; j < i; j++) {
			if (input[j] < input[i]) {
				if (count[i] < count[j] + 1) {
					count[i] = count[j] + 1;
					before[i] = j;
				}
			}
		}
	}

	int max = count[0];
	int idx = 0;
	for (int i = 1; i < N; i++) {
		if (max < count[i]) {
			max = count[i];
			idx = i;
		}
	}

	cout << max << "\n";

	vector<int> V;
	
	while (true) {
		if (idx == -1) break;

		V.push_back(input[idx]);
		idx = before[idx];
	}

	for (int i = max - 1; i >= 0; i--) {
		cout << V[i] << " ";
	}

	return 0;
}
