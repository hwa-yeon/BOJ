#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

static int dx[] = { -1,0,1,0 };
static int dy[] = { 0, -1,0,1 };

static int N, M;
static vector< vector<int> > in;
static vector< vector<bool> > visited;
static queue < pair<int, int> > Q;
static int cnt;
static int mindate;

void BFS();

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M >> N;

	in.resize(N, vector<int>(M));
	visited.resize(N, vector<bool>(M, false));
	cnt = 0;
	mindate = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int num;
			cin >> num;
			in[i][j] = num;

			if (num == 1) {
				Q.push(make_pair(i, j));
				visited[i][j] = true;
				cnt++;
			}
		}
	}

	BFS();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (in[i][j] == 0) {
				mindate = 0;
			}
		}
	}

	cout << mindate - 1 << "\n";

	return 0;
}

void BFS() {

	int temp = 0;

	while (!Q.empty()) {
		pair<int, int> now = Q.front();
		Q.pop();
		cnt--;

		for (int i = 0; i < 4; i++) {
			int x = now.first + dx[i];
			int y = now.second + dy[i];

			if (x >= 0 && y >= 0 && x < N && y < M) {
				if (!visited[x][y]) {
					visited[x][y] = true;

					if (in[x][y] == 0) {
						Q.push(make_pair(x, y));
						in[x][y] = 1;
						temp++;
					}
				}
			}
		}

		if (cnt == 0) {
			mindate++;
			cnt = temp;
			temp = 0;
		}
	}
}
