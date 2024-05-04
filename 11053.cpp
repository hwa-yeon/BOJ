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

	vector<int> in;
	vector<int> cnt;
	in.resize(N);
	cnt.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> in[i];
	}

	cnt[0] = 1;
	for (int i = 1; i < N; i++) {
		cnt[i] = 1;
		for (int j = 0; j < i; j++) {
			if (in[j] < in[i]) {
				cnt[i] = max(cnt[i], cnt[j] + 1);
			}
		}
	}
	sort(cnt.begin(), cnt.end());

	cout << cnt[N - 1] << "\n";

	return 0;
}
