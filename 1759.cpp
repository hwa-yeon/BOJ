#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int L, C;
vector<char> input;
vector<char> output;
vector<bool> visited;

void func(int idx, int depth) {

	if (depth == L) {
		int a = 0;
		int b = 0;
		for (int i = 0; i < L; i++) {
			if (output[i] == 'a' || output[i] == 'e' || output[i] == 'i' || output[i] == 'o' || output[i] == 'u')
				a++;
			else
				b++;
		}
		if (a < 1 || b < 2) return;

		for (int i = 0; i < L; i++) {
			cout << output[i];
		}
		cout << "\n";
		return;
	}

	for (int i = idx; i < C; i++) {
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

	cin >> L >> C;
	input.resize(C);
	visited.resize(C, false);
	output.resize(L);

	for (int i = 0; i < C; i++) {
		char ch;
		cin >> ch;
		input[i] = ch;
	}
	sort(input.begin(), input.end());
	func(0, 0);

	return 0;
}
