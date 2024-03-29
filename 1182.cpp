#include <iostream>
#include <vector>
using namespace std;

int N, S;
int cnt = 0;
vector<int> input;

void func(int depth, int sum) {

	if (depth == N) {
		if (sum == S) cnt++;
		return;
	}

	func(depth + 1, sum);
	func(depth + 1, sum + input[depth]);
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> S;

	input.resize(N);
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		input[i] = num;
	}

	func(0, 0);
	if (S == 0) cnt--;
	cout << cnt << "\n";

	return 0;
}
