#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int S, P;
    cin >> S >> P;

    string dnaStr;
    cin >> dnaStr;
    vector<char> dnaChar(dnaStr.begin(), dnaStr.end());

    vector<int> dnaMin(4);
    for(int i = 0; i < 4; i++) {
        cin >> dnaMin[i];
    }

    vector<int> dnaSub(4, 0);
    for(int i = 0; i < P; i++) {
        if(dnaChar[i] == 'A') dnaSub[0]++;
        else if(dnaChar[i] == 'C') dnaSub[1]++;
        else if(dnaChar[i] == 'G') dnaSub[2]++;
        else if(dnaChar[i] == 'T') dnaSub[3]++;
    }

    int count = 0;
    for(int i = 1; (i + P - 1) <= S; i++) {
        if(dnaSub[0] >= dnaMin[0] && dnaSub[1] >= dnaMin[1] && dnaSub[2] >= dnaMin[2] && dnaSub[3] >= dnaMin[3]) {
            count++;
            if((i + P - 1) == S) {
            break;
            }
        }

        if(dnaChar[i - 1] == 'A') dnaSub[0]--;
        else if(dnaChar[i - 1] == 'C') dnaSub[1]--;
        else if(dnaChar[i - 1] == 'G') dnaSub[2]--;
        else if(dnaChar[i - 1] == 'T') dnaSub[3]--;

        if(dnaChar[i + P - 1] == 'A') dnaSub[0]++;
        else if(dnaChar[i + P - 1] == 'C') dnaSub[1]++;
        else if(dnaChar[i + P - 1] == 'G') dnaSub[2]++;
        else if(dnaChar[i + P - 1] == 'T') dnaSub[3]++;
    }

    cout << count << "\n";

    return 0;
}
