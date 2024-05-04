#include <iostream>
#include <vector>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	vector<long long> P;
	P.resize(101);
	P[1] = 1;
	P[2] = 1;
	P[3] = 1;
	P[4] = 2;
	P[5] = 2;
	for (int i = 6; i <= 100; i++) {
		P[i] = P[i - 1] + P[i - 5];
	}

	while (T--) {
		int N;
		cin >> N;

		cout << P[N] << "\n";
	}

	return 0;
}
