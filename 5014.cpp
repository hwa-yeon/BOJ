#include <iostream>
#include <vector>
#include <queue>
using namespace std;

static int F, S, G, U, D;
static vector<int> stair;
static vector<bool> visited;
static bool arrive = false;

void BFS(int node);

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> F >> S >> G >> U >> D;
	stair.resize(F + 1, 0);
	visited.resize(F + 1, false);

	BFS(S);
	if (arrive) {
		cout << stair[G] << "\n";
	}
	else {
		cout << "use the stairs" << "\n";
	}

	return 0;
}

void BFS(int node) {

	queue<int> Q;
	Q.push(node);
	visited[node] = true;

	while (!Q.empty()) {
		int now = Q.front();
		Q.pop();
		if (now == G) {
			arrive = true;
			break;
		}

		if ((now + U) >= 1 && (now + U) <= F && !visited[now + U]) {
			Q.push(now + U);
			visited[now + U] = true;
			stair[now + U] = stair[now] + 1;
		}
		if ((now - D) >= 1 && (now - D) <= F && !visited[now - D]) {
			Q.push(now - D);
			visited[now - D] = true;
			stair[now - D] = stair[now] + 1;
		}
	}
}
