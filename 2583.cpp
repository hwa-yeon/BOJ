#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

static int dx[] = { 0, 1, 0, -1 };
static int dy[] = { 1, 0, -1, 0 };

static int M, N, K;
static vector< vector<int> > input;
static vector< vector<bool> > visited;

int BFS(int a, int b);

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M >> N >> K;
	input.resize(M, vector<int>(N, 0));
	visited.resize(M, vector<bool>(N, false));

	while (K--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		for (int i = y1; i < y2; i++) {
			for (int j = x1; j < x2; j++) {
				input[i][j] = 1;
			}
		}
	}


	vector<int> V;
	int C = 0;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j] && input[i][j] == 0) {
				int result = BFS(i, j);
				V.push_back(result);
				C++;
			}
		}
	}
	sort(V.begin(), V.end());

	cout << C << "\n";
	for (int i = 0; i < V.size(); i++) {
		cout << V[i] << " ";
	}
	cout << "\n";

	return 0;
}

int BFS(int a, int b) {

	int count = 0;

	queue< pair<int, int> > Q;
	Q.push(make_pair(a, b));
	visited[a][b] = true;

	while (!Q.empty()) {
		pair<int, int> now = Q.front();
		Q.pop();
		count++;

		for (int i = 0; i < 4; i++) {
			int y = now.first + dy[i];
			int x = now.second + dx[i];

			if (y >= 0 && x >= 0 && y < M && x < N) {
				if (!visited[y][x] && input[y][x] == 0) {
					Q.push(make_pair(y, x));
					visited[y][x] = true;
				}
			}
		}
	}

	return count;
}
