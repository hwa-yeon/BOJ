#include <iostream>
#include <vector>
using namespace std;

static vector<int> A;

int fibo(int number);

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    A.resize(N + 1);
    
    for(int i = 0; i <= N; i++) {
        A[i] = -1;
    }

    A[0] = 0;
    A[1] = 1;

    cout << fibo(N) << "\n";

    return 0;
}

int fibo(int number) {

    if(A[number] != -1) return A[number];

    A[number] = fibo(number - 2) + fibo(number - 1);
    return A[number];
}
