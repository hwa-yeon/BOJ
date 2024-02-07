#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> edge;

static vector< vector<edge> > A;
static vector<bool> visited;
static vector<int> leng;

void BFS(int node);

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    A.resize(N + 1);

    for(int i = 0; i < N; i++) {
        int S;
        cin >> S;
        while(true) {
            int E, V;
            cin >> E;
            if(E == -1) break;
            cin >> V;
            A[S].push_back(edge(E, V));
        }
    }

    leng = vector<int>(N + 1, 0);
    visited = vector<bool>(N + 1, false);

    BFS(1);
    int maxNode = 1;
    for(int i = 2; i <= N; i++) {
        if(leng[maxNode] < leng[i]) maxNode = i;
    }

    fill(leng.begin(), leng.end(), 0);
    fill(visited.begin(), visited.end(), false);

    BFS(maxNode);
    sort(leng.begin(), leng.end());
    
    cout << leng[N] << endl;

    return 0;
}

void BFS(int node) {
    
    queue<int> myqueue;
    myqueue.push(node);
    visited[node] = true;

    while(!myqueue.empty()) {
        int nowNode = myqueue.front();
        myqueue.pop();
        for(edge i : A[nowNode]) {
            if(!visited[i.first]) {
                visited[i.first] = true;
                myqueue.push(i.first);
                leng[i.first] = leng[nowNode] + i.second;
            }
        }
    }
}
