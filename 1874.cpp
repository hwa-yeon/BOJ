#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    
    vector<int> A(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    stack<int> mystack;
    int number = 1;
    int index = 1;
    string result;
    while(index <= n) {
        if(mystack.empty() || mystack.top() < A[index]) {
            mystack.push(number);
            result += "+\n";
            number++; 
        }
        else if(mystack.top() == A[index]) {
            mystack.pop();
            result += "-\n";
            index++;
        }
        else {
            cout << "NO" << "\n";
            break;
        }
    }

    if(mystack.empty()) {
        cout << result;
    }

    return 0;
}
