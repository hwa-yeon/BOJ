#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

struct cmp {
    bool operator()(int n1, int n2) {
        if(abs(n1) > abs(n2)) {
            return true;
        }
        else if(abs(n1) == abs(n2)) {
            if(n1 > n2) {
                return true;
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }
};

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    priority_queue<int, vector<int>, cmp> myqueue;
    for(int i = 0; i < N; i++) {
        int input;
        cin >> input;
        if(input == 0) {
            if(myqueue.empty()) {
                cout << "0" << "\n";
            }
            else {
                cout << myqueue.top() << "\n";
                myqueue.pop();
            }
        }
        else {
            myqueue.push(input);
        }
    }

    return 0;
}
