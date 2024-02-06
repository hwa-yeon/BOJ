#include <iostream>
#include <vector>
using namespace std;

static vector< vector<int> > A;
static vector<bool> visited;
static bool arrive;

void DFS(int now, int depth);

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    arrive = false;
    A.resize(N);
    visited = vector<bool>(N, false);

    for(int i = 0; i < M; i++) {
        int s, e;
        cin >> s >> e;
        A[s].push_back(e);
        A[e].push_back(s);
    }

    for(int i = 0; i < N; i++) {
        DFS(i, 1);
        if(arrive) break;
    }

    if(arrive) cout << 1 << endl;
    else cout << 0 << endl;

    return 0;
}

void DFS(int now, int depth) {

    if(depth == 5) {
        arrive = true;
        return;
    }
    visited[now] = true;

    for(int i : A[now]) {
        if(!visited[i]) {
            DFS(i, depth + 1);
        }
    }
    visited[now] = false;
}
