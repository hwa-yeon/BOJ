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

    vector< pair<int,int> > A(N);

    for(int i = 0; i < N; i++) { // 정렬할 때 종료시간이 우선순위가 높도록
        cin >> A[i].second >> A[i].first;
    }

    sort(A.begin(), A.end());

    int count = 0;
    int end = -1;

    for(int i = 0; i < N; i++) {
        if(A[i].second >= end) {
            end = A[i].first;
            count++;
        }
    }
    cout << count << endl;

    return 0;
}
