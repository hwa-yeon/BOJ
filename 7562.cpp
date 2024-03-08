#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

static int dx[] = { -1, 1, -2, 2, -1, 1, -2, 2 };
static int dy[] = { 2, 2, 1, 1, -2, -2, -1, -1 };

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	while (T--) {
		int l;
		cin >> l;

		vector< vector<bool> > visited;
		visited.resize(l, vector<bool>(l, false));

		pair<int, int> start;
		pair<int, int> end;
		cin >> start.first >> start.second;
		cin >> end.first >> end.second;

		queue< pair<int, int> > Q;
		int count = 0;
		int temp = 0;
		int result = 0;

		Q.push(make_pair(start.first, start.second));
		visited[start.first][start.second] = true;
		count++;

		while (!Q.empty()) {
			pair<int, int> now = Q.front();
			Q.pop();
			count--;

			if (now.first == end.first && now.second == end.second) {
				break;
			}

			for (int i = 0; i < 8; i++) {
				int x = now.first + dx[i];
				int y = now.second + dy[i];

				if (x >= 0 && y >= 0 && x < l && y < l) {
					if (!visited[x][y]) {
						Q.push(make_pair(x, y));
						visited[x][y] = true;
						temp++;
					}
				}
			}

			if (count == 0) {
				count = temp;
				temp = 0;
				result++;
			}
		}
		cout << result << "\n";
	}

	return 0;
}
