#include <iostream>
#include <vector>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector< pair<int, int> > fibo;
	fibo.resize(41);
	fibo[0] = make_pair(1, 0);
	fibo[1] = make_pair(0, 1);

	for (int i = 2; i < 41; i++) {
		fibo[i] = make_pair(fibo[i - 1].first + fibo[i - 2].first, fibo[i - 1].second + fibo[i - 2].second);
	}

	int T;
	cin >> T;

	while (T--) {
		int N;
		cin >> N;
		cout << fibo[N].first << " " << fibo[N].second << "\n";
	}

	return 0;
}
