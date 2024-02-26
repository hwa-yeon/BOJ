#include <iostream>
#include <stack>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	stack< pair<int, int> > mystack;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;

		while (!mystack.empty()) {
			if (num < mystack.top().second) {
				cout << mystack.top().first << " ";
				break;
			}
			mystack.pop();
		}
		if (mystack.empty()) {
			cout << 0 << " ";
		}

		mystack.push(make_pair(i + 1, num));
	}
	cout << "\n";

	return 0;
}
