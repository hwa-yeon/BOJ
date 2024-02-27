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
	int same = 0;
	long long sum = 0;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;

		same = 1;
		while (!mystack.empty() && mystack.top().first <= num) {
			if (mystack.top().first == num) {
				same = same + mystack.top().second;
			}
			sum += mystack.top().second;
			mystack.pop();
		}

		if (!mystack.empty()) {
			sum += 1;
		}

		mystack.push(make_pair(num, same));
	}
	cout << sum << "\n";

	return 0;
}
