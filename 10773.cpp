#include <iostream>
#include <stack>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int K;
	cin >> K;

	stack<int> mystack;
	for (int i = 0; i < K; i++) {
		int n;
		cin >> n;
		if (n == 0) {
			mystack.pop();
		}
		else {
			mystack.push(n);
		}
	}

	int sum = 0;
	while (!mystack.empty()) {
		sum += mystack.top();
		mystack.pop();
	}

	cout << sum << "\n";

	return 0;
}
