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

	vector<int> input;
	input.resize(N);

	vector<int> tmp;
	tmp.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> input[i];
		tmp[i] = input[i];
	}

	sort(tmp.begin(), tmp.end());
	tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());

	for (int i = 0; i < N; i++) {
		cout << lower_bound(tmp.begin(), tmp.end(), input[i]) - tmp.begin() << " ";
	}
	cout << "\n";

	return 0;
}
