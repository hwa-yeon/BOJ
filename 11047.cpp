#include <iostream>
#include <vector>
using namespace std;

int main() {

	int N, K;
	cin >> N >> K;

	vector<int> coin;
	coin.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> coin[i];
	}

	int result = 0;
	for (int i = N - 1; i >= 0; i--) {
		if (K == 0) break;

		result += K / coin[i];
		K %= coin[i];
	}

	cout << result << "\n";

	return 0;
}
