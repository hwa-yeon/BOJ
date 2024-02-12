#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

static int N, M;
static vector< vector<int> > tree;
static vector<int> depth;
static int kMax;
static int parent[21][100001];
static vector<bool> visited;

void BFS(int node);
int LCA(int a, int b);

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    tree.resize(N + 1);

    for(int i = 0; i < N - 1; i++) {
        int s, e;
        cin >> s >> e;
        tree[s].push_back(e);
        tree[e].push_back(s);
    }

    depth.resize(N + 1);
    visited.resize(N + 1);

    int temp = 1;
    kMax = 0;
    while(temp <= N) {
        temp *= 2;
        kMax++; 
    }

    BFS(1);

    for(int k = 1; k <= kMax; k++) {
        for(int n = 1; n <= N; n++) {
            parent[k][n] = parent[k - 1][parent[k - 1][n]];
        }
    }

    cin >> M;

    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        int result = LCA(a, b);
        cout << result << "\n";
    }

    return 0;
}

void BFS(int node) {

    queue<int> myqueue;
    myqueue.push(node);
    visited[node] = true;

    int level = 1;
    int nowSize = 1;
    int count = 0;

    while(!myqueue.empty()) {
        int nowNode = myqueue.front();
        myqueue.pop();

        for(int next : tree[nowNode]) {
            if(!visited[next]) {
                myqueue.push(next);
                visited[next] = true;
                parent[0][next] = nowNode;
                depth[next] = level;
            }
        }
        count++;
        if(count == nowSize) {
            count = 0;
            nowSize = myqueue.size();
            level++;
        }
    }
}

int LCA(int a, int b) {

    if(depth[a] > depth[b]) {
        int temp = a;
        a = b;
        b = temp;
    }

    for(int k = kMax; k >= 0; k--) {
        if(pow(2, k) <= (depth[b] - depth[a])) {
            b = parent[k][b];
        }
    }

    for(int k = kMax; k >= 0; k--) {
        if(parent[k][a] != parent[k][b]) {
            a = parent[k][a];
            b = parent[k][b];
        }
    }
    
    int result = a;
    if(a != b) {
        result = parent[0][result];
    }
    return result;
}
