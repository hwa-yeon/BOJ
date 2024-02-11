#include <iostream>
#include <vector>
#include <queue>
using namespace std;

static int N, M;
static vector< vector<int> > tree;
static vector<int> depth;
static vector<int> parent;
static vector<bool> visited;

void BFS(int node);
int LCA(int a, int b);

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    tree.resize(N + 1);
    depth.resize(N + 1);
    parent.resize(N + 1);
    visited.resize(N + 1);

    for(int i = 0; i < N - 1; i++) {
        int s, e;
        cin >> s >> e;
        tree[s].push_back(e);
        tree[e].push_back(s);
    }
    BFS(1);
    
    cin >> M;
    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        int result = LCA(a, b);
        cout << result << endl;
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
                parent[next] = nowNode;
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

    if(depth[a] < depth[b]) {
        int temp = a;
        a = b;
        b = temp;
    }
    while(depth[a] != depth[b]) {
        a = parent[a];
    }
    while(a != b) {
        a = parent[a];
        b = parent[b];
    }
    return a;
}
