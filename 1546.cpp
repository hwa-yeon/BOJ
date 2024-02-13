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
    vector<int> score(N);
    int maxScore = 0;
    int sumScore = 0;
    for(int i = 0; i < N; i++) {
        cin >> score[i];
        maxScore = max(maxScore, score[i]);
        sumScore += score[i];
    }
    double avgScore = (double)sumScore / (double)N;
    double result = (double)avgScore / (double)maxScore * 100;
    cout << result << "\n";

    return 0;
}
