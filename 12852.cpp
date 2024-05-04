#include <iostream>
#include <vector>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> cnt;
	cnt.resize(N + 1);
	cnt[1] = 0;

	vector<int> num;
	num.resize(N + 1);
	num[1] = 1;

	for (int i = 2; i <= N; i++) {
		cnt[i] = cnt[i - 1] + 1;
		num[i] = i - 1;

		if (i % 2 == 0 && cnt[i / 2] < cnt[i]) {
			cnt[i] = cnt[i / 2] + 1;
			num[i] = i / 2;
		}
		if (i % 3 == 0 && cnt[i / 3] < cnt[i]) {
			cnt[i] = cnt[i / 3] + 1;
			num[i] = i / 3;
		}
	}

	cout << cnt[N] << "\n";

	int cur = N;
	while (true) {
		cout << cur << " ";

		if (cur == 1) break;

		cur = num[cur];
	}

	return 0;
}
