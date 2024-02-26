#include <iostream>
#include <stack>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	stack<int> mystack;
	long long sum = 0;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;

		while (!mystack.empty() && mystack.top() <= num) {
			mystack.pop();
		}

		sum += mystack.size();
		mystack.push(num);
	}
	cout << sum << "\n";

	return 0;
}
