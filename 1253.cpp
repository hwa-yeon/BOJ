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

	vector<int> A(N, 0);

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	sort(A.begin(), A.end());

	int result = 0;
	for (int i = 0; i < N; i++) {
		long find = A[i];
		int start = 0;
		int end = N - 1;

		while (start < end) {
			if ((A[start] + A[end]) == find) {
				if ((start != i) && (end != i)) {
					result++;
					break;
				}
				else if (start == i) {
					start++;
				}
				else if (end == i) {
					end--;
				}
			}
			else if ((A[start] + A[end]) < find) {
				start++;
			}
			else {
				end--;
			}
		}
	}

	cout << result << endl;

	return 0;
}
