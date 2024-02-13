#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    string sNum;
    cin >> sNum;

    vector<char> cNum(sNum.begin(), sNum.end());

    int sum = 0;
    for(int i = 0; i < cNum.size(); i++) {
        sum += cNum[i] - '0';
    }
    cout << sum << "\n";

    return 0;
}
