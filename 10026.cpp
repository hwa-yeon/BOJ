#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

static int dx[] = { 0, 1, 0, -1 };
static int dy[] = { 1 ,0 ,-1 ,0 };

static int N;
static vector< vector<char> > in;
static vector< vector<bool> > visited;

void BFS(int a, int b);

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	in.resize(N, vector<char>(N));
	visited.resize(N, vector<bool>(N, false));

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;

		for (int j = 0; j < str.length(); j++) {
			in[i][j] = str[j];
		}
	}

	int result1 = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				BFS(i, j);
				result1++;
			}
		}
	}

	visited.clear();
	visited.resize(N, vector<bool>(N, false));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (in[i][j] == 'G') {
				in[i][j] = 'R';
			}
		}
	}

	int result2 = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				BFS(i, j);
				result2++;
			}
		}
	}

	cout << result1 << " " << result2 << "\n";

	return 0;
}

void BFS(int a, int b) {

	char find = in[a][b];

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
				if (!visited[x][y] && in[x][y] == find) {
					Q.push(make_pair(x, y));
					visited[x][y] = true;
				}
			}
		}
	}
}
