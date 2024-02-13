#include <iostream>
#include <vector>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int start = 1;
    int end = 1;
    int sum = 1;
    int cnt = 1;
    while(end != N) {
        if(sum == N) {
            cnt++;
            end++;
            sum += end;
        }
        else if(sum < N) {
            end++;
            sum += end;
        }
        else {
            sum -= start;
            start++;
        }
    }
    cout << cnt << "\n";

    return 0;
}
