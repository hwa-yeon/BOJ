#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

static int dx[4] = {0, 1, 0, -1};
static int dy[4] = {1, 0, -1, 0};
static vector< vector<bool> > visited;
static vector< vector<int> > A;
static int N, M;

void BFS(int i, int j);

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    A.resize(N, vector<int>(M));
    visited.resize(N, vector<bool>(M, false));

    for(int i = 0; i < N; i++) {
        string line;
        cin >> line;
        vector<char> lineCh(line.begin(), line.end());
        for(int j = 0; j < M; j++) {
            A[i][j] = lineCh[j] - '0';
        }
    }

    BFS(0, 0);
    cout << A[N - 1][M - 1] << "\n";

    return 0;
}

void BFS(int i, int j) {

    queue< pair<int, int> > myqueue;
    myqueue.push(make_pair(i, j));
    visited[i][j] = true;
    
    while(!myqueue.empty()) {
        pair<int, int> now = myqueue.front();
        myqueue.pop();

        for(int k = 0; k < 4; k++) {
            int x = now.first + dx[k];
            int y = now.second + dy[k];

            if(x >= 0 && y >= 0 && x < N && y < M) {
                if(A[x][y] != 0 && !visited[x][y]) {
                    myqueue.push(make_pair(x, y));
                    visited[x][y] = true;
                    A[x][y] = A[now.first][now.second] + 1;
                }
            }
        }
    }
}
