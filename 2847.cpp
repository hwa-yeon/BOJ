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

	vector<int> score;
	score.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> score[i];
	}

	int cur = score[N - 1];
	int result = 0;
	for (int i = N - 2; i >= 0; i--) {
		if (score[i] >= cur) {
			result += score[i] - cur + 1;
			cur -= 1;
		}
		else {
			cur = score[i];
		}
	}

	cout << result << "\n";

	return 0;
}
