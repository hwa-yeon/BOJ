#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

static int dx[] = { -1,0,1,0 };
static int dy[] = { 0, -1,0,1 };

static vector< vector<int> > in;
static vector< vector<bool> > visited;

void BFS(int a, int b, int M, int N);

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	while (T--) {
		int M, N, K;
		cin >> M >> N >> K;

		in.resize(M, vector<int>(N, 0));
		visited.resize(M, vector<bool>(N, false));

		while (K--) {
			int x, y;
			cin >> x >> y;
			in[x][y] = 1;
		}

		int result = 0;
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if(in[i][j] && !visited[i][j]) {
					BFS(i, j, M, N);
					result++;
				}
			}
		}

		cout << result << "\n";
		in.clear();
		visited.clear();
	} 

	return 0;
}

void BFS(int a, int b, int M, int N) {

	queue < pair<int, int> > Q;
	Q.push(make_pair(a, b));
	visited[a][b] = true;

	while (!Q.empty()) {
		pair<int, int> now = Q.front();
		Q.pop();

		for (int i = 0; i < 4; i++) {
			int x = now.first + dx[i];
			int y = now.second + dy[i];

			if (x >= 0 && y >= 0 && x < M && y < N) {
				if (in[x][y] && !visited[x][y]) {
					Q.push(make_pair(x, y));
					visited[x][y] = true;
				}
			}
		}
	}
}
