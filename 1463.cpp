#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> A(N + 1);
    A[1] = 0;

    for(int i = 2; i <=N; i++) {
        A[i] = A[i - 1] + 1;
        if(i % 2 == 0) {
            A[i] = min(A[i], A[i / 2] + 1);
        }
        if(i % 3 == 0) {
            A[i] = min(A[i], A[i / 3] + 1);
        }
    }
    cout << A[N] << "\n";

    return 0;
}
