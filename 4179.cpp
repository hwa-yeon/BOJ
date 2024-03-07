#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

static int dx[] = { -1,0,1,0 };
static int dy[] = { 0, -1,0,1 };

static int R, C;
static vector< vector<char> > in;
static queue < pair<int, int> > JQ, FQ;
static int jihun, fire;
static int cnt;

void BFS();

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C;

	in.resize(R, vector<char>(C));

	jihun = 1;
	fire = 0;
	cnt = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			char c;
			cin >> c;
			in[i][j] = c;

			if (c == 'J') {
				JQ.push(make_pair(i, j));
			}
			else if (c == 'F') {
				FQ.push(make_pair(i, j));
				fire++;
			}
		}
	}

	BFS();

	if (cnt == -1) {
		cout << "IMPOSSIBLE" << "\n";
	}
	else {
		cout << cnt << "\n";
	}

	return 0;
}

void BFS() {

	int Jtemp = 0;
	int Ftemp = 0;

	while (!JQ.empty()) {

		for (int i = 0; i < R; i++) {
			if (in[i][0] == 'J' || in[i][C - 1] == 'J') {
				cnt++;
				return;
			}
		}

		for (int i = 0; i < C; i++) {
			if (in[0][i] == 'J' || in[R - 1][i] == 'J') {
				cnt++;
				return;
			}
		}

		while (jihun--) {
			pair<int, int> Jnow = JQ.front();
			JQ.pop();

			if (in[Jnow.first][Jnow.second] == 'F') {
				continue;
			}

			for (int i = 0; i < 4; i++) {
				int x = Jnow.first + dx[i];
				int y = Jnow.second + dy[i];

				if (x >= 0 && y >= 0 && x < R && y < C) {
					if (in[x][y] == '.') {
						JQ.push(make_pair(x, y));
						in[x][y] = 'J';
						Jtemp++;
					}	
				}
			}
		}

		jihun = Jtemp;
		Jtemp = 0;
		cnt++;

		while (fire--) {
			pair<int, int> Fnow = FQ.front();
			FQ.pop();

			for (int i = 0; i < 4; i++) {
				int x = Fnow.first + dx[i];
				int y = Fnow.second + dy[i];

				if (x >= 0 && y >= 0 && x < R && y < C) {
					if (in[x][y] == '.' || in[x][y] == 'J') {
						FQ.push(make_pair(x, y));
						in[x][y] = 'F';
						Ftemp++;
					}
				}
			}
		}

		fire = Ftemp;
		Ftemp = 0;
	}
	cnt = -1;
}
