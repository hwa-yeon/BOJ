#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N;

	vector<int> input;
	input.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> input[i];
	}
	sort(input.begin(), input.end());

	cin >> M;
	while (M--) {
		int num;
		cin >> num;

		cout << binary_search(input.begin(), input.end(), num) << " ";
	}
	cout << "\n";

	return 0;
}
