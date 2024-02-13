#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string N;
    cin >> N;

    vector<char> Nchar(N.begin(), N.end());
    sort(Nchar.begin(), Nchar.end(), greater<char>());

    for(int i = 0; i < Nchar.size(); i++) {
        cout << Nchar[i];
    }
    cout << "\n";

    return 0;
}
