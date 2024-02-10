#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

static vector<long> tree;

void setTree(int index);
void changeVal(int index, long value);
long getSum(int s, int e);

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;

    int treeHeight = 0;
    int length = N;

    while(length != 0) {
        length /= 2;
        treeHeight++;
    }

    int treeSize = pow(2, treeHeight + 1);
    int leftNodeStartIndex = treeSize / 2;

    tree.resize(treeSize + 1);

    for(int i = leftNodeStartIndex; i < leftNodeStartIndex + N; i++) {
            cin >> tree[i];
    }

    setTree(treeSize - 1);

    for(int i = 0; i < M + K; i++) {
        long a, s, e;
        cin >> a >> s >> e;
        if(a == 1) {
            changeVal(leftNodeStartIndex + s - 1, e);
        } 
        else if(a == 2) {
            long sum = getSum(leftNodeStartIndex + s -1, leftNodeStartIndex + e - 1);
            cout << sum << endl;
        }
    }

    return 0;
}

void setTree(int index) {

    while(index != 1) {
        tree[index / 2] += tree[index];
        index--;
    }
}

void changeVal(int index, long value) {

    long diff = value - tree[index];
    while(index > 0) {
        tree[index] += diff;
        index /= 2;
    }
}

long getSum(int s, int e) {

    long partSum = 0;
    while(s <= e) {
        if(s % 2 == 1) {
            partSum += tree[s];
        }
        if(e % 2 == 0) {
            partSum += tree[e];
        }
        s = (s + 1) / 2;
        e = (e - 1) / 2;
    }
    return partSum;
}
