#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

static int dx[] = { 0, -1, 0, 1 };
static int dy[] = { 1, 0, -1, 0 };

static int N;
static vector< vector<int> > input;
static vector< vector<int> > output;
static vector< vector<bool> > visited;

void BFS(int a, int b);

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	input.resize(N, vector<int>(N));
	output.resize(N, vector<int>(N, 0));
	visited.resize(N, vector<bool>(N, false));

	int maxNum = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int num;
			cin >> num;
			input[i][j] = num;
			maxNum = max(maxNum, num);
		}
	}

	int count = 0;
	int result = 1;
	for (int k = 0; k <= maxNum; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (input[i][j] <= k) {
					output[i][j] = 1;
				}
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[i][j] && !output[i][j]) {
					BFS(i, j);
					count++;
				}
			}
		}
		result = max(result, count);

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				output[i][j] = 0;
				visited[i][j] = false;
			}
		}
		count = 0;
	}

	cout << result << "\n";

	return 0;
}

void BFS(int a, int b) {

	queue< pair<int, int> > Q;
	Q.push(make_pair(a, b));
	visited[a][b] = true;

	while (!Q.empty()) {
		pair<int, int> now = Q.front();
		Q.pop();

		for (int i = 0; i < 4; i++) {
			int x = now.first + dx[i];
			int y = now.second + dy[i];

			if (x >= 0 && y >= 0 && x < N && y < N) {
				if (!visited[x][y] && !output[x][y]) {
					Q.push(make_pair(x, y));
					visited[x][y] = true;
				}
			}
		}
	}
}
