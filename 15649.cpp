#include <iostream>
#include <vector>
using namespace std;

static int N, M;
static vector<int> A;
static vector<bool> visited;

void DFS(int depth);

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	A.resize(M);
	visited.resize(N + 1, false);

	DFS(0);

	return 0;
}

void DFS(int depth) {
	if (depth == M) {
		for (int i = 0; i < M; i++) {
			cout << A[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			A[depth] = i;
			DFS(depth + 1);
			visited[i] = false;
		}
	}
}
