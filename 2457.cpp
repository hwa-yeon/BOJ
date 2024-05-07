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

	vector< pair<int, int> > flower;
	flower.resize(N);

	for (int i = 0; i < N; i++) {
		int startMonth, startDay, endMonth, endDay;
		cin >> startMonth >> startDay >> endMonth >> endDay;
		flower[i] = make_pair(startMonth * 100 + startDay, endMonth * 100 + endDay);
	}

	sort(flower.begin(), flower.end());

	int result = 0;
	int cur = 301;
	while (cur < 1201) {
		int next = cur;
		for (int i = 0; i < N; i++) {
			if (flower[i].first <= cur && flower[i].second > next) {
				next = flower[i].second;
			}
		}

		if (cur == next) {
			result = 0;
			break;
		}

		result++;
		cur = next;
	}

	cout << result << "\n";

	return 0;
}
