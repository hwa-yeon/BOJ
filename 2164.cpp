#include <iostream>
#include <queue>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    
    queue<int> myqueue;
    for(int i = 1; i <= N; i++) {
        myqueue.push(i);
    }

    int temp = 0;
    while(!myqueue.empty()) {
        temp = myqueue.front();
        myqueue.pop();

        myqueue.push(myqueue.front());
        myqueue.pop();
    }
    cout << temp << "\n";

    return 0;
}
