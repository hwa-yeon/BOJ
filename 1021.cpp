#include <iostream>
#include <deque>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	deque<int> D;
	for (int i = 1; i <= N; i++) {
		D.push_back(i);
	}

	int result = 0;
	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;

		int left = 0;
		int right = 0;
		for (int j = 0; j < D.size(); j++) {
			if (D[j] == num) {
				left = j;
				right = D.size() - j - 1;
				break;
			}
		}
		if (left <= right) {
			while (D.front() != num) {
				D.push_back(D.front());
				D.pop_front();
				result++;
			}
			D.pop_front();
		}
		else {
			while (D.back() != num) {
				D.push_front(D.back());
				D.pop_back();
				result++;
			}
			D.pop_back();
			result++;
		}
	}
	cout << result << "\n";

	return 0;
}
