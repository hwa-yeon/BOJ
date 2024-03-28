#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static int N, M;
static vector<int> input;
static vector<int> A;
//static vector<bool> visited;

void DFS(int numer, int depth);

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	A.resize(M);
	input.resize(N);
	//visited.resize(N, false);

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		input[i] = num;
	}
	sort(input.begin(), input.end());

	DFS(0, 0);

	return 0;
}

void DFS(int number, int depth) {
	if (depth == M) {
		for (int i = 0; i < M; i++) {
			cout << A[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = number; i < N; i++) {
		//if (!visited[i]) {
			//visited[i] = true;
			A[depth] = input[i];
			DFS(i, depth + 1);
			//visited[i] = false;
		//}
	}
}
