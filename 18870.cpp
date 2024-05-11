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

	vector<int> temp;
	for (int i = 0; i < N; i++) {
		if (i == 0 || tmp[i] != tmp[i - 1]) {
			temp.push_back(tmp[i]);
		}
	}

	for (int i = 0; i < N; i++) {
		cout << lower_bound(temp.begin(), temp.end(), input[i]) - temp.begin() << " ";
	}
	cout << "\n";

	return 0;
}
