#include <iostream>
#include <vector>
#include <queue>
using namespace std;

static int dx[] = { -1,0,1,0 };
static int dy[] = { 0, -1,0,1 };

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	while (T--) {

		int w, h;
		vector< vector<char> > in;
		queue < pair<int, int> > SQ, FQ;

		int cnt;

		cin >> w >> h;

		in.resize(h, vector<char>(w));

		cnt = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				char c;
				cin >> c;
				in[i][j] = c;

				if (c == '@') {
					SQ.push(make_pair(i, j));
				}
				else if (c == '*') {
					FQ.push(make_pair(i, j));
				}
			}
		}

		bool find = false;
		while (!SQ.empty()) {

			if (find) {
				break;
			}

			int fsize = FQ.size();
			while (fsize--) {
				pair<int, int> Fnow = FQ.front();
				FQ.pop();

				for (int i = 0; i < 4; i++) {
					int x = Fnow.first + dx[i];
					int y = Fnow.second + dy[i];

					if (x >= 0 && y >= 0 && x < h && y < w) {
						if (in[x][y] == '.' || in[x][y] == '@') {
							FQ.push(make_pair(x, y));
							in[x][y] = '*';
						}
					}
				}
			}

			int ssize = SQ.size();
			while (ssize--) {
				pair<int, int> Snow = SQ.front();
				SQ.pop();

				for (int i = 0; i < 4; i++) {
					int x = Snow.first + dx[i];
					int y = Snow.second + dy[i];

					if (!(x >= 0 && y >= 0 && x < h && y < w)) {
						find = true;
						break;
					}
					else {
						if (in[x][y] == '.') {
							SQ.push(make_pair(x, y));
							in[x][y] = '@';
						}
					}
				}
			}
			cnt++;
		}

		if (!find) {
			cout << "IMPOSSIBLE" << "\n";
		}
		else {
			cout << cnt << "\n";
		}
	}

	return 0;
}
