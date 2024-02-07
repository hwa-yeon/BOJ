#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long min, max;
    cin >> min >> max;
    vector<int> A;
    vector<bool> visited(10000001, false);

    for(int i = 2; i < 10000001; i++) {
        if(visited[i]) continue;
        A.push_back(i);
        for(int j = i + i; j < 10000001; j += i) visited[j] = true;
    }

    int count = 0;
    // 거의 소수 구하기
    for(int i : A) {
        long long cur = 1LL * i;
        long long temp = cur;
        while(temp <= max / cur) {
            temp = temp * cur;
            if(temp >= min) count++;
        }
    
    }
    cout << count << "\n";

    return 0;
}
