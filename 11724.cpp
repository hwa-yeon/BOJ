#include <iostream>
#include <stack>
#include <vector>
using namespace std;

static int N, M;
static vector< vector<int> > graph;
static vector<bool> visited;

void DFS(int node);

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    graph.resize(N + 1);
    visited = vector<bool>(N + 1, false);

    for(int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int count = 0;
    for(int i = 1; i <= N; i++) {
        if(!visited[i]) {
            DFS(i);
            count++;
        }
    }
    cout << count << "\n";

    return 0;
}

void DFS(int node) {

    visited[node] = true;
    for(int n : graph[node]) {
        if(!visited[n]) {
            DFS(n);
        }
    }
}
