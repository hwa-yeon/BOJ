#include <iostream>
#include <vector>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<long long> V;
	V.resize(N);
	
	V[0] = 1;
	V[1] = 1;
	for (int i = 2; i < N; i++) {
		V[i] = V[i - 2] + V[i - 1];
	}

	cout << V[N - 1] << "\n";

	return 0;
}
