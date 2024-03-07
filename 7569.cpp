#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

static int dx[] = { -1, 0, 1, 0, 0, 0 };
static int dy[] = { 0, -1, 0, 1, 0, 0 };
static int dh[] = { 0, 0, 0, 0, -1, 1 };

static int M, N, H;
static vector< vector< vector<int> > > in;
static vector< vector< vector<bool> > > visited;
static queue < pair<int, pair<int, int> > > Q;
static int cnt;
static int mindate;

void BFS();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M >> N >> H;
	in.resize(N, vector< vector<int> >(M, vector<int>(H)));
	visited.resize(N, vector< vector<bool> >(M, vector<bool>(H)));

	cnt = 0;
	mindate = 0;

	for (int k = 0; k < H; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				int num;
				cin >> num;
				in[i][j][k] = num;

				if (num == 1) {
					Q.push(make_pair(i, make_pair(j, k)));
					visited[i][j][k] = true;
					cnt++;
				}
			}
		}
	}

	BFS();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < H; k++) {
				if (in[i][j][k] == 0) {
					mindate = 0;
				}
			}
		}
	}

	cout << mindate - 1 << "\n";

	return 0;
}

void BFS() {

	int temp = 0;

	while (!Q.empty()) {
		pair<int, pair<int, int> > now = Q.front();
		Q.pop();
		cnt--;

		for (int i = 0; i < 6; i++) {
			int x = now.first + dx[i];
			int y = now.second.first + dy[i];
			int h = now.second.second + dh[i];

			if (x >= 0 && y >= 0 && h >= 0 && x < N && y < M && h < H) {
				if (!visited[x][y][h]) {
					visited[x][y][h] = true;

					if (in[x][y][h] == 0) {
						Q.push(make_pair(x, make_pair(y, h)));
						in[x][y][h] = 1;
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
