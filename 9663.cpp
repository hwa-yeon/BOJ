#include <iostream>
#include <vector>
using namespace std;

int N;
int cnt = 0;
vector<bool> visited1;
vector<bool> visited2;
vector<bool> visited3;

void func(int cur) {

	if (cur == N) {
		cnt++;
		return;
	}

	for (int i = 0; i < N; i++) {
		if (!visited1[i] && !visited2[cur + i] && !visited3[cur - i + N - 1]) {
			visited1[i] = true;
			visited2[cur + i] = true;
			visited3[cur - i + N - 1] = true;
			func(cur + 1);
			visited1[i] = false;
			visited2[cur + i] = false;
			visited3[cur - i + N - 1] = false;
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	visited1.resize(N, false);
	visited2.resize(2 * N - 1, false);
	visited3.resize(2 * N - 1, false);

	func(0);
	cout << cnt << "\n";

	return 0;
}
