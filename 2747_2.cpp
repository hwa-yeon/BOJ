#include <iostream>
#include <vector>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> A(N + 1, -1);
    A[0] = 0;
    A[1] = 1;
    
    for(int i = 2; i <= N; i++) {
        A[i] = A[i - 1] + A[i - 2];
    }

    cout << A[N] << "\n";

    return 0;
}
