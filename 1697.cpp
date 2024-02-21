#include <iostream>
#include <vector>
#include <queue>
using namespace std;

static int N, K;
static vector<bool> visited(100001, false);

void BFS(int node, int time);

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	BFS(N, 0);

	return 0;
}

void BFS(int node, int time) {

	queue< pair<int, int> > myqueue;
	myqueue.push(make_pair(node, time));
	visited[node] = true;

	while (!myqueue.empty()) {
		pair<int, int> now = myqueue.front();
		myqueue.pop();

		if (now.first == K) {
			cout << now.second << "\n";
			break;
		}

		if (now.first - 1 >= 0 && now.first - 1 <= 100000) {
			if (!visited[now.first - 1]) {
				myqueue.push(make_pair(now.first - 1, now.second + 1));
				visited[now.first] = true;
			}
		}
		if (now.first + 1 >= 0 && now.first + 1 <= 100000) {
			if (!visited[now.first + 1]) {
				myqueue.push(make_pair(now.first + 1, now.second + 1));
				visited[now.first] = true;
			}
		}
		if (now.first * 2 >= 0 && now.first * 2 <= 100000) {
			if (!visited[now.first * 2]) {
				myqueue.push(make_pair(now.first * 2, now.second + 1));
				visited[now.first] = true;
			}
		}
	}
}
