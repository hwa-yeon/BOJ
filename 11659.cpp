#include <iostream>
#include <vector>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    vector<int> input(N + 1, 0);
    vector<int> sum(N + 1, 0);

    for(int i = 1; i <= N; i++) {
        cin >> input[i];
        sum[i] = sum[i - 1] + input[i];
    }
    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        int result = sum[b] - sum[a - 1];
        cout << result << "\n";
    }

    return 0;
}
