#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> input;
vector<int> visited;
vector<int> output = vector<int>(6);

void func(int idx, int depth) {

	if (depth == 6) {
		for (int i = 0; i < 6; i++) {
			cout << output[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = idx; i < N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			output[depth] = input[i];
			func(i + 1, depth + 1);
			visited[i] = false;
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true) {
		cin >> N;
		if (N == 0) break;

		input.resize(N);
		visited.resize(N, false);
		for (int i = 0; i < N; i++) {
			int num;
			cin >> num;
			input[i] = num;
		}

		func(0, 0);
		cout << "\n";

		input.clear();
		visited.clear();
	}

	return 0;
}
