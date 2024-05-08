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
	
	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;

		int start = 0;
		int end = N - 1;
		int mid;
		int result = 0;

		while (start <= end) {
			mid = (start + end) / 2;

			if (input[mid] == num) {
				result = 1;
				break;
			}
			else if (input[mid] < num) {
				start = mid + 1;
			}
			else {
				end = mid - 1;
			}
		}

		cout << result << "\n";
	}

	return 0;
}
