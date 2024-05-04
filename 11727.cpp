#include <iostream>
#include <vector>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<int> V;
	V.resize(n);

	V[0] = 1;
	V[1] = 3;
	for (int i = 2; i < n; i++) {
		V[i] = ((2 * V[i - 2]) + V[i - 1]) % 10007;
	}

	cout << V[n - 1] << "\n";

	return 0;
}
