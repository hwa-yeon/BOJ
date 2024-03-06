#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

static int dx[] = { -1,0,1,0 };
static int dy[] = { 0, -1,0,1 };

static int n, m;
static vector< vector<int> > in;
static vector< vector<bool> > visited;
static int cnt;

void BFS(int a, int b);

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	in.resize(n, vector<int>(m));
	visited.resize(n, vector<bool>(m, false));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int num;
			cin >> num;
			in[i][j] = num;
		}
	}

	int count = 0;
	int result = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j] && in[i][j] == 1) {
				cnt = 0;
				BFS(i, j);
				result = max(result, cnt);
				count++;
			}
		}
	}

	cout << count << "\n";
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
		cnt++;

		for (int i = 0; i < 4; i++) {
			int x = now.first + dx[i];
			int y = now.second + dy[i];

			if (x >= 0 && y >= 0 && x < n && y < m) {
				if (!visited[x][y] && in[x][y] == 1) {
					Q.push(make_pair(x, y));
					visited[x][y] = true;
				}
			}
		}
	}
}
