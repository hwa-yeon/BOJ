#include <iostream>
#include <vector>
#include <queue>
using namespace std;

static int dx[] = { 0, 1, 0, -1 };
static int dy[] = { 1, 0, -1, 0 };

vector< vector<char> > input;
vector<bool> pick;
int result = 0;

bool isMoreThanFour();
bool BFS();
void DFS(int index, int depth);

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input.resize(5, vector<char>(5));
	pick.resize(25, false);

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			char ch;
			cin >> ch;
			input[i][j] = ch;
		}
	}

	DFS(0, 0);
	cout << result << "\n";

	return 0;
}

bool isMoreThanFour() {
	
	int sum = 0;
	for (int i = 0; i < 25; i++) {
		if (pick[i] && input[i / 5][i % 5] == 'S') sum++;
	}

	if (sum >= 4) return true;
	else return false;
}

bool BFS() {

	queue< pair<int, int> > Q;
	vector< vector<bool> > visited;
	visited.resize(5, vector<bool>(5, false));

	for (int i = 0; i < 25; i++) {
		if (pick[i]) {
			visited[i / 5][i % 5] = true;
			Q.push(make_pair(i / 5, i % 5));
			break;
		}
	}

	int count = 1;
	while (!Q.empty()) {
		if (count == 7) {
			return true;
		}

		pair<int, int> now = Q.front();
		Q.pop();
		for (int i = 0; i < 4; i++) {
			int x = now.first + dx[i];
			int y = now.second + dy[i];

			if (x >= 0 && y >= 0 && x < 5 && y < 5) {
				if (pick[5 * x + y] && !visited[x][y]) {
					visited[x][y] = true;
					Q.push(make_pair(x, y));
					count++;
				}
			}
		}
	}

	return false;
}

void DFS(int index, int depth) {

	if (depth == 7) {
		if (isMoreThanFour() && BFS()) {
			result++;
		}
		return;
	}

	for (int i = index; i < 25; i++) {
		if (!pick[i]) {
			pick[i] = true;
			DFS(i + 1, depth + 1);
			pick[i] = false;
		}
	}
}
