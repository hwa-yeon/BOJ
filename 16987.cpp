#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector< pair<int, int> > input;
int result = 0;

void func(int depth) {

	if (depth == N) {
		int count = 0;
		for (int i = 0; i < N; i++) {
			if (input[i].first <= 0) count++;
		}
		result = max(result, count);
		return;
	}

	if (input[depth].first <= 0) {
		func(depth + 1);
		return;
	}

	bool check = false;
	for (int i = 0; i < N; i++) {
		if (i == depth) continue;
		if (input[i].first <= 0) continue;

		check = true;
		input[depth].first -= input[i].second;
		input[i].first -= input[depth].second;

		func(depth + 1);

		input[depth].first += input[i].second;
		input[i].first += input[depth].second;
	}

	if (!check) {
		func(depth + 1);
		return;
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	input.resize(N);

	for (int i = 0; i < N; i++) {
		int S, W;
		cin >> S >> W;
		input[i] = make_pair(S, W);
	}

	func(0);
	cout << result << "\n";

	return 0;
}
