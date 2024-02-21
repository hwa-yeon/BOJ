#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

static int dx[4] = { 0, 1, 0, -1 };
static int dy[4] = { 1, 0, -1, 0 };
static int N;
static vector< vector<int> > graph;
static vector< vector<bool> > visited;
static vector<int> house;

void BFS(int a, int b);

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	graph.resize(N, vector<int>(N));
	visited.resize(N, vector<bool>(N, false));

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		vector<char> ch(str.begin(), str.end());
		for (int j = 0; j < N; j++) {
			graph[i][j] = ch[j] - '0';
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j] && graph[i][j] == 1) {
				BFS(i, j);
			}
		}
	}

	sort(house.begin(), house.end());

	cout << house.size() << "\n";
	for (int i = 0; i < house.size(); i++) {
		cout << house[i] << "\n";
	}

	return 0;
}

void BFS(int a, int b) {

	queue< pair<int, int> > myqueue;
	myqueue.push(make_pair(a, b));
	visited[a][b] = true;
	
	int count = 0;
	while (!myqueue.empty()) {
		pair<int, int> now = myqueue.front();
		myqueue.pop();
		count++;

		for (int i = 0; i < 4; i++) {
			int x = now.first + dx[i];
			int y = now.second + dy[i];
			if (x >= 0 && y >= 0 && x < N && y < N) {
				if (!visited[x][y] && graph[x][y] == 1) {
					myqueue.push(make_pair(x, y));
					visited[x][y] = true; 
				}
			}
		}
	}
	house.push_back(count);
}
